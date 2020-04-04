import("stdfaust.lib");

process = os.osc(hslider("sine_freq",100,20,20000,1):si.smoo)<:_,_;