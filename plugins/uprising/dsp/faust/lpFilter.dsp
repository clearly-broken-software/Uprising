import("stdfaust.lib");
lpFilter= fi.resonlp(lpfCuttoff,lpfQ,lpfGain);
lpfCuttoff = hslider("lpfCuttoff",20000,0,20000,0.1);
lpfQ = hslider("lpQ",1,0,20,0.1);
lpfGain = hslider("filterGain",1,0,1,0.01);
process = lpFilter;import("stdfaust.lib");