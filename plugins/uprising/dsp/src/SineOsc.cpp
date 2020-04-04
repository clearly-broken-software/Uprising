
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: SineOsc.dsp
// Name: SineOsc
// Author: 
// Copyright: 
// License: 
// Version: 
//------------------------------------------------------------------------------







#include "SineOsc.hpp"



#include <utility>
#include <cmath>

class SineOsc::BasicDsp {
public:
    virtual ~BasicDsp() {}
};

//------------------------------------------------------------------------------
// Begin the Faust code section

namespace {

template <class T> inline T min(T a, T b) { return (a < b) ? a : b; }
template <class T> inline T max(T a, T b) { return (a > b) ? a : b; }

class Meta {
public:
    // dummy
    void declare(...) {}
};

class UI {
public:
    // dummy
    void openHorizontalBox(...) {}
    void openVerticalBox(...) {}
    void closeBox(...) {}
    void declare(...) {}
    void addButton(...) {}
    void addCheckButton(...) {}
    void addVerticalSlider(...) {}
    void addHorizontalSlider(...) {}
    void addVerticalBargraph(...) {}
    void addHorizontalBargraph(...) {}
};

typedef SineOsc::BasicDsp dsp;

} // namespace

#define FAUSTPP_VIRTUAL // do not declare any methods virtual
#define FAUSTPP_PRIVATE public // do not hide any members
#define FAUSTPP_PROTECTED public // do not hide any members

// define the DSP in the anonymous namespace
#define FAUSTPP_BEGIN_NAMESPACE namespace {
#define FAUSTPP_END_NAMESPACE }


#if defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#ifndef FAUSTPP_PRIVATE
#   define FAUSTPP_PRIVATE private
#endif
#ifndef FAUSTPP_PROTECTED
#   define FAUSTPP_PROTECTED protected
#endif
#ifndef FAUSTPP_VIRTUAL
#   define FAUSTPP_VIRTUAL virtual
#endif

#ifndef FAUSTPP_BEGIN_NAMESPACE
#   define FAUSTPP_BEGIN_NAMESPACE
#endif
#ifndef FAUSTPP_END_NAMESPACE
#   define FAUSTPP_END_NAMESPACE
#endif

FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

FAUSTPP_END_NAMESPACE
#include <algorithm>
#include <cmath>
#include <math.h>
FAUSTPP_BEGIN_NAMESPACE

class mydspSIG0 {
	
  FAUSTPP_PRIVATE:
	
	int iRec0[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	int getInputRatemydspSIG0(int channel) {
		int rate;
		switch ((channel)) {
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	int getOutputRatemydspSIG0(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 0;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec0[l0] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec0[0] = (iRec0[1] + 1);
			table[i] = std::sin((9.58738019e-05f * float((iRec0[0] + -1))));
			iRec0[1] = iRec0[0];
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float ftbl0mydspSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 FAUSTPP_PRIVATE:
	
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fHslider0;
	float fRec2[2];
	float fRec1[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.1");
		m->declare("filename", "SineOsc.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.2");
		m->declare("name", "SineOsc");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.1");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
	}

	FAUSTPP_VIRTUAL int getNumInputs() {
		return 0;
	}
	FAUSTPP_VIRTUAL int getNumOutputs() {
		return 2;
	}
	FAUSTPP_VIRTUAL int getInputRate(int channel) {
		int rate;
		switch ((channel)) {
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	FAUSTPP_VIRTUAL int getOutputRate(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	
	static void classInit(int sample_rate) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(sample_rate);
		sig0->fillmydspSIG0(65536, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = (1.0f / std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate))));
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(100.0f);
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
		}
	}
	
	FAUSTPP_VIRTUAL void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	FAUSTPP_VIRTUAL void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	FAUSTPP_VIRTUAL mydsp* clone() {
		return new mydsp();
	}
	
	FAUSTPP_VIRTUAL int getSampleRate() {
		return fSampleRate;
	}
	
	FAUSTPP_VIRTUAL void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("SineOsc");
		ui_interface->addHorizontalSlider("sine_freq", &fHslider0, 100.0f, 20.0f, 20000.0f, 1.0f);
		ui_interface->closeBox();
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = (0.00100000005f * float(fHslider0));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec2[0] = (fSlow0 + (0.999000013f * fRec2[1]));
			float fTemp0 = (fRec1[1] + (fConst0 * fRec2[0]));
			fRec1[0] = (fTemp0 - std::floor(fTemp0));
			float fTemp1 = ftbl0mydspSIG0[int((65536.0f * fRec1[0]))];
			output0[i] = FAUSTFLOAT(fTemp1);
			output1[i] = FAUSTFLOAT(fTemp1);
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
		}
	}

};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif



//------------------------------------------------------------------------------
// End the Faust code section




SineOsc::SineOsc()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();

}

SineOsc::~SineOsc()
{
}

void SineOsc::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();

}

void SineOsc::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();

}

void SineOsc::process(
    
    float *out0,float *out1,
    unsigned count) noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    float *inputs[] = {
        
    };
    float *outputs[] = {
        out0,out1,
    };
    dsp.compute(count, inputs, outputs);

}

const char *SineOsc::parameter_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "sine_freq";
    
    default:
        return 0;
    }
}

const char *SineOsc::parameter_short_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    default:
        return 0;
    }
}

const char *SineOsc::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "sine_freq";
    
    default:
        return 0;
    }
}

const char *SineOsc::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    default:
        return 0;
    }
}

const SineOsc::ParameterRange *SineOsc::parameter_range(unsigned index) noexcept
{
    switch (index) {
    
    case 0: {
        static const ParameterRange range = { 100, 20, 20000 };
        return &range;
    }
    
    default:
        return 0;
    }
}

bool SineOsc::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool SineOsc::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool SineOsc::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool SineOsc::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

float SineOsc::get_parameter(unsigned index) const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        return dsp.fHslider0;
    
    default:
        (void)dsp;
        return 0;
    }
}

void SineOsc::set_parameter(unsigned index, float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        dsp.fHslider0 = value;
        break;
    
    default:
        (void)dsp;
        (void)value;
        break;
    }
}


float SineOsc::get_sine_freq() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}


void SineOsc::set_sine_freq(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}




