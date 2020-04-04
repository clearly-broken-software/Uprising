import("stdfaust.lib");
declare author "Bart Brouns";
declare license "GPLv3";

xVal = hslider("xVal", 0, 0, maxSamples, 1)/defaultSR*ma.SR;
yVal = hslider("yVal", 0, 0, 1, 0.001);
slope = hslider("slope", 0, -1, 1, 0.001);
goBtn = button("resetBtn");//:ba.impulsify;

maxSeconds = 5;
maxSamples = maxSeconds*defaultSR;
defaultSR = 48000;

process =
  envelope;

// ramp from 0 to 1 in n samples.
// when reset == 1, go back to 0.
ramp(n,reset) = select2(reset,_+(1/n):min(1),0)~_;


xVal_target(reset)  = rwtable(3, 0.0,nextValIndex(reset),xVal,currentValIndex(reset));
yVal_target(reset)  = rwtable(3, 0.0,nextValIndex(reset),yVal,currentValIndex(reset));

currentValIndex(reset) = reset :ba.toggle;
nextValIndex(reset) = currentValIndex(reset)*-1+1;

xfade(a,b,x) = a*(1-x)+b*x;

envelope = FB~_ with {
  FB(prev) = ((xfade(ba.sAndH(reset),yVal_target(reset),position)+(yVal*startPulse))~(_))
            ,(reset':ba.impulsify:hbargraph("[1]endpoint", 0, 1))
  with {
  reset = ( (prev==yVal_target(_)) :xor(goBtn) )~(_<:(_,_));
  position = ramp(xVal_target(reset),reset):hbargraph("[0]position", 0, 1);
  // the commented out stuff is WIP for changing the curve of the ramp
  // position = ramp(xVal_target(reset),reset):hbargraph("pos", 0, 1):pow(power):max(0):min(1);
  };
  startPulse = 1-1';
  // power = select2(slope<0,slope*px+1,1+slope*mx):hbargraph("power", 0, 10);
  // px = hslider("px", 1, 1, 9, 1);
  // mx = hslider("mx", 0.5, 0, 1, 0.001);
};