
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: SinLFO.dsp
// Name: SinLFO
// Author: 
// Copyright: 
// License: 
// Version: 
//------------------------------------------------------------------------------







#include "SinLFO.hpp"



#include <utility>
#include <cmath>

class SinLFO::BasicDsp {
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

typedef SinLFO::BasicDsp dsp;

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
		switch (channel) {
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	int getOutputRatemydspSIG0(int channel) {
		int rate;
		switch (channel) {
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
	
	void instanceInitmydspSIG0(int samplingFreq) {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec0[l0] = 0;
			
		}
		
	}
	
	void fillmydspSIG0(int count, float* output) {
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec0[0] = (iRec0[1] + 1);
			output[i] = std::sin((9.58738019e-05f * float((iRec0[0] + -1))));
			iRec0[1] = iRec0[0];
			
		}
		
	}

};

mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

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
	
	int fSamplingFreq;
	float fConst0;
	FAUSTFLOAT fHslider0;
	float fRec1[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("filename", "SinLFO");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "SinLFO");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.0");
	}

	FAUSTPP_VIRTUAL int getNumInputs() {
		return 0;
		
	}
	FAUSTPP_VIRTUAL int getNumOutputs() {
		return 1;
		
	}
	FAUSTPP_VIRTUAL int getInputRate(int channel) {
		int rate;
		switch (channel) {
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	FAUSTPP_VIRTUAL int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
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
	
	static void classInit(int samplingFreq) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(samplingFreq);
		sig0->fillmydspSIG0(65536, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
		
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = (1.0f / std::min<float>(192000.0f, std::max<float>(1.0f, float(fSamplingFreq))));
		
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(100.0f);
		
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
			
		}
		
	}
	
	FAUSTPP_VIRTUAL void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	
	FAUSTPP_VIRTUAL void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	FAUSTPP_VIRTUAL mydsp* clone() {
		return new mydsp();
	}
	
	FAUSTPP_VIRTUAL int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	FAUSTPP_VIRTUAL void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("SinLFO");
		ui_interface->addHorizontalSlider("freq", &fHslider0, 100.0f, 0.00999999978f, 100.0f, 0.00999999978f);
		ui_interface->closeBox();
		
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst0 * float(fHslider0));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec1[0] = (fSlow0 + (fRec1[1] - std::floor((fSlow0 + fRec1[1]))));
			output0[i] = FAUSTFLOAT(ftbl0mydspSIG0[int((65536.0f * fRec1[0]))]);
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




SinLFO::SinLFO()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();

}

SinLFO::~SinLFO()
{
}

void SinLFO::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();

}

void SinLFO::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();

}

void SinLFO::process(
    
    float *out0,
    unsigned count) noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    float *inputs[] = {
        
    };
    float *outputs[] = {
        out0,
    };
    dsp.compute(count, inputs, outputs);

}

const char *SinLFO::parameter_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "freq";
    
    default:
        return 0;
    }
}

const char *SinLFO::parameter_short_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    default:
        return 0;
    }
}

const char *SinLFO::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "freq";
    
    default:
        return 0;
    }
}

const char *SinLFO::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    default:
        return 0;
    }
}

const SinLFO::ParameterRange *SinLFO::parameter_range(unsigned index) noexcept
{
    switch (index) {
    
    case 0: {
        static const ParameterRange range = { 100, 0.0099999998, 100 };
        return &range;
    }
    
    default:
        return 0;
    }
}

bool SinLFO::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool SinLFO::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool SinLFO::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool SinLFO::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

float SinLFO::get_parameter(unsigned index) const noexcept
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

void SinLFO::set_parameter(unsigned index, float value) noexcept
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


float SinLFO::get_freq() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}


void SinLFO::set_freq(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}




