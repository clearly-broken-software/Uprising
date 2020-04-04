
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: NoiseOsc.dsp
// Name: NoiseOsc
// Author: 
// Copyright: 
// License: 
// Version: 
//------------------------------------------------------------------------------







#include "../NoiseOsc.hpp"



#include <utility>
#include <cmath>

class NoiseOsc::BasicDsp {
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

typedef NoiseOsc::BasicDsp dsp;

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
FAUSTPP_BEGIN_NAMESPACE


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
	int iRec0[2];
	int fSamplingFreq;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("filename", "NoiseOsc");
		m->declare("name", "NoiseOsc");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.0");
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
		
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec0[l0] = 0;
			
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
		ui_interface->openVerticalBox("NoiseOsc");
		ui_interface->addHorizontalSlider("noiseGain", &fHslider0, 1.0f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->closeBox();
		
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (4.65661287e-10f * float(fHslider0));
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec0[0] = ((1103515245 * iRec0[1]) + 12345);
			output0[i] = FAUSTFLOAT((fSlow0 * float(iRec0[0])));
			iRec0[1] = iRec0[0];
			
		}
		
	}

};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif



//------------------------------------------------------------------------------
// End the Faust code section




NoiseOsc::NoiseOsc()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();

}

NoiseOsc::~NoiseOsc()
{
}

void NoiseOsc::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();

}

void NoiseOsc::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();

}

void NoiseOsc::process(
    
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

const char *NoiseOsc::parameter_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "noiseGain";
    
    default:
        return 0;
    }
}

const char *NoiseOsc::parameter_short_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    default:
        return 0;
    }
}

const char *NoiseOsc::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "noiseGain";
    
    default:
        return 0;
    }
}

const char *NoiseOsc::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    default:
        return 0;
    }
}

const NoiseOsc::ParameterRange *NoiseOsc::parameter_range(unsigned index) noexcept
{
    switch (index) {
    
    case 0: {
        static const ParameterRange range = { 1, 0, 1 };
        return &range;
    }
    
    default:
        return 0;
    }
}

bool NoiseOsc::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool NoiseOsc::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool NoiseOsc::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool NoiseOsc::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

float NoiseOsc::get_parameter(unsigned index) const noexcept
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

void NoiseOsc::set_parameter(unsigned index, float value) noexcept
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


float NoiseOsc::get_noiseGain() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}


void NoiseOsc::set_noiseGain(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}




