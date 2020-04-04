import("stdfaust.lib");
pitchenv(timeInSeconds,pitchStart,pitchEnd) = up
with{
  rs1 = timeInSeconds * ma.SR;
  up = ba.countup(rs1,0) : ba.bpf.start(0,pitchStart) : ba.bpf.end(rs1,pitchEnd);
};

pe = pitchenv(10,55,440);
process = os.osc(pe);
