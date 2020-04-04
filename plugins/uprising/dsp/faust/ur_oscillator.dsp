import("stdfaust.lib");

gate = 1-button("gate"); // starts the ramp envelope
// general purpose ramp envelope
env(start,end,len) = urRamp
with {
    urRamp = ba.countup(len,gate): ba.bpf.start(0,start): ba.bpf.end(len,end);//:si.smoo;
};

// constant power panning ; reference The Audio Programming Book p.236
piOver2 = ma.PI/2;
root2over2 = (2 : sqrt) * 0.5;
angle = pan * piOver2 * 0.5;
posLeft = root2over2 * (cos(angle) - sin(angle));
posRight = root2over2 * (cos(angle) + sin(angle));

panStartPos = hslider("panStartPosition",0,-1,1,0.001);
panEndPos =   hslider("panEndPosition",  0,-1,1,0.001);
pan = env(panStartPos,panEndPos,bufferSize);

// oscilator
oscType = hslider("oscType",0,0,4,1);
oscStartFreq = hslider("oscStartFreq", 440, 20, 20000,0.01);
oscEndFreq = hslider("oscEndFreq", 440, 20, 20000, 0.01);
bufferSize = hslider("bufferSize", 1024, 1, 10 * 44100,1);
oscStartGain = hslider("oscStartGain", 1, 0, 1, 0.001);
oscEndGain = hslider("oscEndGain",1,0,1,0.001);

oscAmp = env(oscStartGain,oscEndGain,bufferSize);
oscPitchRamp = env(oscStartFreq,oscEndFreq,bufferSize);
oscFreq = oscPitchRamp + LFO;

urOsc = ba.selectmulti(ma.SR/10,(os.osc(oscFreq),os.triangle(oscFreq),os.sawtooth(oscFreq),os.square(oscFreq),no.noise),oscType)*oscAmp;

// lfo
lfoStartFreq = hslider("lfoStartFreq", 6, 0, 15, 0.001);
lfoEndFreq = hslider("lfoEndFreq", 6, 0.001, 15, 0.001);
lfoStartDepth = hslider("lfoStartDepth", 0, 0,1, 0.001);
lfoEndDepth = hslider("lfoEndDepth", 0, 0,1, 0.001);

lfoPitchRamp = env(lfoStartFreq,lfoEndFreq,bufferSize);
lfoDepthRamp = env(lfoStartDepth,lfoEndDepth,bufferSize);

LFO = os.lf_triangle(lfoPitchRamp)*lfoDepthRamp*20;

// filter
filterType = hslider ("filterType",0,0,3,1);
filterGain = hslider ("filterGain",1,0,1,0.001);
filterQ = hslider("filterQ",1,1,20,1);
filterFreq = hslider("filterFreq",20000,20,20000,0.001);
lpf = fi.resonlp(filterFreq,filterQ,filterGain);

process = 1 - gate : si.smoo * urOsc:lpf<:_*posLeft,_*posRight;