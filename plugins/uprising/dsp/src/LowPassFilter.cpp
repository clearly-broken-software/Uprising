
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: lpFilter.dsp
// Name: lpFilter
// Author: 
// Copyright: 
// License: 
// Version: 
//------------------------------------------------------------------------------







#include "../LowPassFilter.hpp"

#include <utility>
#include <cmath>

class LowPassFilter::BasicDsp {
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

typedef LowPassFilter::BasicDsp dsp;

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

static float mydsp_faustpower2_f(float value) {
	return (value * value);
	
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 FAUSTPP_PRIVATE:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSamplingFreq;
	float fConst0;
	FAUSTFLOAT fHslider2;
	float fRec0[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("filename", "lpFilter");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "lpFilter");
	}

	FAUSTPP_VIRTUAL int getNumInputs() {
		return 1;
		
	}
	FAUSTPP_VIRTUAL int getNumOutputs() {
		return 1;
		
	}
	FAUSTPP_VIRTUAL int getInputRate(int channel) {
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
		
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = (3.14159274f / std::min<float>(192000.0f, std::max<float>(1.0f, float(fSamplingFreq))));
		
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(20000.0f);
		
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; (l0 < 3); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
			
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
		ui_interface->openVerticalBox("lpFilter");
		ui_interface->addHorizontalSlider("filterGain", &fHslider0, 1.0f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("lpQ", &fHslider1, 1.0f, 0.0f, 20.0f, 0.100000001f);
		ui_interface->addHorizontalSlider("lpfCuttoff", &fHslider2, 20000.0f, 0.0f, 20000.0f, 0.100000001f);
		ui_interface->closeBox();
		
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (1.0f / float(fHslider1));
		float fSlow1 = std::tan((fConst0 * float(fHslider2)));
		float fSlow2 = (1.0f / fSlow1);
		float fSlow3 = (((fSlow0 + fSlow2) / fSlow1) + 1.0f);
		float fSlow4 = (float(fHslider0) / fSlow3);
		float fSlow5 = (1.0f / fSlow3);
		float fSlow6 = (((fSlow2 - fSlow0) / fSlow1) + 1.0f);
		float fSlow7 = (2.0f * (1.0f - (1.0f / mydsp_faustpower2_f(fSlow1))));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec0[0] = (float(input0[i]) - (fSlow5 * ((fSlow6 * fRec0[2]) + (fSlow7 * fRec0[1]))));
			output0[i] = FAUSTFLOAT((fSlow4 * (fRec0[2] + (fRec0[0] + (2.0f * fRec0[1])))));
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			
		}
		
	}

};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif



//------------------------------------------------------------------------------
// End the Faust code section




LowPassFilter::LowPassFilter()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();

}

LowPassFilter::~LowPassFilter()
{
}

void LowPassFilter::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();

}

void LowPassFilter::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();

}

void LowPassFilter::process(
    const float *in0,
    float *out0,
    unsigned count) noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    float *inputs[] = {
        const_cast<float *>(in0),
    };
    float *outputs[] = {
        out0,
    };
    dsp.compute(count, inputs, outputs);

}

const char *LowPassFilter::parameter_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "filterGain";
    
    case 1:
        return "lpQ";
    
    case 2:
        return "lpfCuttoff";
    
    default:
        return 0;
    }
}

const char *LowPassFilter::parameter_short_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    default:
        return 0;
    }
}

const char *LowPassFilter::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "filterGain";
    
    case 1:
        return "lpQ";
    
    case 2:
        return "lpfCuttoff";
    
    default:
        return 0;
    }
}

const char *LowPassFilter::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    default:
        return 0;
    }
}

const LowPassFilter::ParameterRange *LowPassFilter::parameter_range(unsigned index) noexcept
{
    switch (index) {
    
    case 0: {
        static const ParameterRange range = { 1, 0, 0 };
        return &range;
    }
    
    case 1: {
        static const ParameterRange range = { 1, 0, 20 };
        return &range;
    }
    
    case 2: {
        static const ParameterRange range = { 20000, 0, 20000 };
        return &range;
    }
    
    default:
        return 0;
    }
}

bool LowPassFilter::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool LowPassFilter::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool LowPassFilter::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool LowPassFilter::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

float LowPassFilter::get_parameter(unsigned index) const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        return dsp.fHslider0;
    
    case 1:
        return dsp.fHslider1;
    
    case 2:
        return dsp.fHslider2;
    
    default:
        (void)dsp;
        return 0;
    }
}

void LowPassFilter::set_parameter(unsigned index, float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        dsp.fHslider0 = value;
        break;
    
    case 1:
        dsp.fHslider1 = value;
        break;
    
    case 2:
        dsp.fHslider2 = value;
        break;
    
    default:
        (void)dsp;
        (void)value;
        break;
    }
}


float LowPassFilter::get_filterGain() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}

float LowPassFilter::get_lpQ() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider1;
}

float LowPassFilter::get_lpfCuttoff() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider2;
}


void LowPassFilter::set_filterGain(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}

void LowPassFilter::set_lpQ(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider1 = value;
}

void LowPassFilter::set_lpfCuttoff(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider2 = value;
}




