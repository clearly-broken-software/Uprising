import("stdfaust.lib");

gate = abs(button("gate")-1);

ramp(timeInSeconds,start,end,rgate) = up
with{
  rs1 = timeInSeconds * ma.SR;
  up = ba.countup(rs1,rgate) : ba.bpf.start(0,start) : ba.bpf.end(rs1,end);
};

myFilter = fi.resonbp(fc,q,gain)
with{
    fc = ramp(5,20,2000,gate);
    q = hslider("q",20,1,20,0.01);
    gain = hslider("gain",0.5,0,1,0.01);
};

process = no.noise:myFilter;

import("stdfaust.lib");
gate = 1-button("gate");
startFreq = 880;
endFreq = 220;
length = ma.SR * 4;
counter = ba.countup(length,gate): ba.bpf.start(0,startFreq) : ba.bpf.end(length,endFreq);
index = 1;
dataPoints = (0,100,100,100);
process = os.osc(counter);

up = ba.countup(rs1,rgate) : ba.bpf.start(0,start) : ba.bpf.end(rs1,end);

//////////////

import("stdfaust.lib");
gate = 1-button("gate");
// general purpose ramp
env(sFreq,eFreq,len) = urRamp
with {
    urRamp = ba.countup(len,gate): ba.bpf.start(0,sFreq): ba.bpf.end(len,eFreq);
};

sineStartFreq = hslider("sineStartFreq", 100, 20, 20000,0.01);
sineEndFreq = hslider("sineEndFreq", 100, 20, 20000, 0.01);
bufferSize = hslider("bufferSize", 512, 1, 2 * 44100,1);
pitchRamp = env(sineStartFreq,sineEndFreq,bufferSize);

// lfo
lfoStartFreq = hslider("lfoStartFreq", 6, 0.001, 15, 0.001);
lfoEndFreq = hslider("lfoEndFreq", 6, 0.001, 15, 0.001);
lfoStartDepth = hslider("lfoStartDepth", 1, 0,1, 0.001);
lfoEndDepth = hslider("lfoEndDepth", 1, 0,1, 0.001);

lfoPitchRamp = env(lfoStartFreq,lfoEndFreq,bufferSize);
lfoDepthRamp = env(lfoStartDepth,lfoEndDepth,bufferSize);
LFO = os.lf_triangle(lfoPitchRamp)*lfoDepthRamp*20;


allFreq = pitchRamp + LFO;
oscAmp = hslider("oscAmp", 0.5, 0, 1, 0.001):si.smoo;
sineOsc = os.osc(allFreq)*oscAmp;

process = sineOsc;



///
import("stdfaust.lib");
gate = 1-button("gate");
// general purpose ramp
env(start,end,len) = urRamp
with {
    urRamp = ba.countup(len,gate): ba.bpf.start(0,start): ba.bpf.end(len,end);//:si.smoo;
};
// sine oscilator
sineStartFreq = hslider("sineStartFreq", 440, 20, 20000,0.01);
sineEndFreq = hslider("sineEndFreq", 440, 20, 20000, 0.01);
bufferSize = hslider("bufferSize", 1024, 1, 2 * 44100,1);
sineStartGain = hslider("sineStartGain", 1, 0, 1, 0.001);
sineEndGain = hslider("sineEndGain",1,0,1,0.001);

sineAmp = env(sineStartGain,sineEndGain,bufferSize);
sinePitchRamp = env(sineStartFreq,sineEndFreq,bufferSize);
sineFreq = sinePitchRamp + LFO;
sineOsc = os.osc(sineFreq)*sineAmp;

// lfo
lfoStartFreq = hslider("lfoStartFreq", 6, 0.001, 15, 0.001);
lfoEndFreq = hslider("lfoEndFreq", 6, 0.001, 15, 0.001);
lfoStartDepth = hslider("lfoStartDepth", 0, 0,1, 0.001);
lfoEndDepth = hslider("lfoEndDepth", 0, 0,1, 0.001);

lfoPitchRamp = env(lfoStartFreq,lfoEndFreq,bufferSize);
lfoDepthRamp = env(lfoStartDepth,lfoEndDepth,bufferSize);

LFO = os.lf_triangle(lfoPitchRamp)*lfoDepthRamp*20;

process = sineOsc;

///////////////////////////////////////

import("stdfaust.lib");
// constant power panning ; reference The Audio Programming Book p.236
piOver2 = ma.PI/2;
root2over2 = (2 : sqrt) * 0.5;
angle = pan * piOver2 * 0.5;
posLeft = root2over2 * (cos(angle) - sin(angle));
posRight = root2over2 * (cos(angle) + sin(angle));

panStartPos = hslider("panStartPosition",0,-1,1,0.001);
panEndPos =   hslider("panEndPosition",  0,-1,1,0.001);
pan = env(panStartPos,panEndPos,bufferSize);


gate = 1-button("gate"); // starts the ramp envelope
// general purpose ramp envelope
env(start,end,len) = urRamp
with {
    urRamp = ba.countup(len,gate): ba.bpf.start(0,start): ba.bpf.end(len,end);//:si.smoo;
};

// sine oscilator
sineStartFreq = hslider("sineStartFreq", 440, 20, 20000,0.01);
sineEndFreq = hslider("sineEndFreq", 440, 20, 20000, 0.01);
bufferSize = hslider("bufferSize", 1024, 1, 2 * 44100,1);
sineStartGain = hslider("sineStartGain", 1, 0, 1, 0.001);
sineEndGain = hslider("sineEndGain",1,0,1,0.001);

sineAmp = env(sineStartGain,sineEndGain,bufferSize);
sinePitchRamp = env(sineStartFreq,sineEndFreq,bufferSize);
sineFreq = sinePitchRamp + LFO;
sineOsc = os.osc(sineFreq)*sineAmp;

// lfo
lfoStartFreq = hslider("lfoStartFreq", 6, 0.001, 15, 0.001);
lfoEndFreq = hslider("lfoEndFreq", 6, 0.001, 15, 0.001);
lfoStartDepth = hslider("lfoStartDepth", 0, 0,1, 0.001);
lfoEndDepth = hslider("lfoEndDepth", 0, 0,1, 0.001);

lfoPitchRamp = env(lfoStartFreq,lfoEndFreq,bufferSize);
lfoDepthRamp = env(lfoStartDepth,lfoEndDepth,bufferSize);

LFO = os.lf_triangle(lfoPitchRamp)*lfoDepthRamp*20;

process = sineOsc<:_*posLeft,_*posRight;

//

import("stdfaust.lib");
// constant power panning ; reference The Audio Programming Book p.236
piOver2 = ma.PI/2;
root2over2 = (2 : sqrt) * 0.5;
angle = pan * piOver2 * 0.5;
posLeft = root2over2 * (cos(angle) - sin(angle));
posRight = root2over2 * (cos(angle) + sin(angle));

panStartPos = hslider("panStartPosition",0,-1,1,0.001);
panEndPos =   hslider("panEndPosition",  0,-1,1,0.001);
pan = env(panStartPos,panEndPos,bufferSize);


gate = 1-button("gate"); // starts the ramp envelope
// general purpose ramp envelope
env(start,end,len) = urRamp
with {
    urRamp = ba.countup(len,gate): ba.bpf.start(0,start): ba.bpf.end(len,end);//:si.smoo;
};

// sine oscilator
sineStartFreq = hslider("sineStartFreq", 440, 20, 20000,0.01);
sineEndFreq = hslider("sineEndFreq", 440, 20, 20000, 0.01);
bufferSize = hslider("bufferSize", 1024, 1, 2 * 44100,1);
sineStartGain = hslider("sineStartGain", 1, 0, 1, 0.001);
sineEndGain = hslider("sineEndGain",1,0,1,0.001);

sineAmp = env(sineStartGain,sineEndGain,bufferSize);
sinePitchRamp = env(sineStartFreq,sineEndFreq,bufferSize);
sineFreq = sinePitchRamp + LFO;
sineOsc = os.osc(sineFreq)*sineAmp;

// lfo
lfoStartFreq = hslider("lfoStartFreq", 6, 0, 15, 0.001);
lfoEndFreq = hslider("lfoEndFreq", 6, 0.001, 15, 0.001);
lfoStartDepth = hslider("lfoStartDepth", 0, 0,1, 0.001);
lfoEndDepth = hslider("lfoEndDepth", 0, 0,1, 0.001);

lfoPitchRamp = env(lfoStartFreq,lfoEndFreq,bufferSize);
lfoDepthRamp = env(lfoStartDepth,lfoEndDepth,bufferSize);

LFO = os.lf_triangle(lfoPitchRamp)*lfoDepthRamp*20;

process = sineOsc<:_*posLeft,_*posRight;
