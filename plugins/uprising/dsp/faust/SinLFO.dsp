import("stdfaust.lib");
freq = hslider("freq",100,0.01,100,0.01);
process = os.oscsin(freq);
			