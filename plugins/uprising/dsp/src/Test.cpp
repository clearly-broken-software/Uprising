
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: test.dsp
// Name: test
// Author: Bart Brouns
// Copyright: 
// License: GPLv3
// Version: 
//------------------------------------------------------------------------------







#include "Test.hpp"



#include <utility>
#include <cmath>

class Test::BasicDsp {
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

typedef Test::BasicDsp dsp;

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
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i = 0; (i < count); i = (i + 1)) {
			table[i] = 0.0f;
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }


#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 FAUSTPP_PRIVATE:
	
	int iVec0[2];
	float ftbl0[3];
	FAUSTFLOAT fHslider0;
	int iRec5[2];
	FAUSTFLOAT fButton0;
	float fRec4[3];
	float ftbl1[3];
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fHslider1;
	int iRec6[2];
	float fRec3[2];
	FAUSTFLOAT fHbargraph0;
	float ftbl2[3];
	float fRec7[2];
	float fRec2[2];
	float fRec0[2];
	FAUSTFLOAT fHbargraph1;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "Bart Brouns");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.1");
		m->declare("filename", "test.dsp");
		m->declare("license", "GPLv3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.2");
		m->declare("name", "test");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.1");
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
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(sample_rate);
		sig0->fillmydspSIG0(3, ftbl0);
		sig0->instanceInitmydspSIG0(sample_rate);
		sig0->fillmydspSIG0(3, ftbl1);
		fConst0 = (2.08333331e-05f * std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate))));
		sig0->instanceInitmydspSIG0(sample_rate);
		sig0->fillmydspSIG0(3, ftbl2);
		deletemydspSIG0(sig0);
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec5[l1] = 0;
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec4[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec6[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec3[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec7[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec2[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec0[l7] = 0.0f;
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
		ui_interface->openVerticalBox("test");
		ui_interface->declare(&fHbargraph0, "0", "");
		ui_interface->addHorizontalBargraph("position", &fHbargraph0, 0.0f, 1.0f);
		ui_interface->declare(&fHbargraph1, "1", "");
		ui_interface->addHorizontalBargraph("endpoint", &fHbargraph1, 0.0f, 1.0f);
		ui_interface->addButton("resetBtn", &fButton0);
		ui_interface->addHorizontalSlider("xVal", &fHslider1, 0.0f, 0.0f, 240000.0f, 1.0f);
		ui_interface->addHorizontalSlider("yVal", &fHslider0, 0.0f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->closeBox();
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fHslider0);
		float fSlow1 = float(fButton0);
		for (int i = 0; (i < count); i = (i + 1)) {
			iVec0[0] = 1;
			iRec5[0] = (iRec5[1] != ((fRec4[1] - fRec4[2]) == 1.0f));
			ftbl0[(1 - iRec5[0])] = fSlow0;
			fRec4[0] = float(((fRec0[1] == ftbl0[iRec5[0]]) ^ int(fSlow1)));
			int iTemp0 = int(fRec4[0]);
			iRec6[0] = (iRec6[1] != ((fRec4[0] - fRec4[1]) == 1.0f));
			int iTemp1 = (1 - iRec6[0]);
			ftbl1[iTemp1] = (fConst0 * float(fHslider1));
			fRec3[0] = (iTemp0 ? 0.0f : std::min<float>(1.0f, (fRec3[1] + (1.0f / ftbl1[iRec6[0]]))));
			fHbargraph0 = FAUSTFLOAT(fRec3[0]);
			ftbl2[iTemp1] = fSlow0;
			fRec7[0] = (iTemp0 ? fRec2[1] : fRec7[1]);
			fRec2[0] = ((fHbargraph0 * ftbl2[iRec6[0]]) + ((fSlow0 * float((1 - iVec0[1]))) + (fRec7[0] * (1.0f - fHbargraph0))));
			fRec0[0] = fRec2[0];
			fHbargraph1 = FAUSTFLOAT((fRec4[1] > fRec4[2]));
			int iRec1 = int(fHbargraph1);
			output0[i] = FAUSTFLOAT(fRec0[0]);
			output1[i] = FAUSTFLOAT(iRec1);
			iVec0[1] = iVec0[0];
			iRec5[1] = iRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			iRec6[1] = iRec6[0];
			fRec3[1] = fRec3[0];
			fRec7[1] = fRec7[0];
			fRec2[1] = fRec2[0];
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




Test::Test()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();

}

Test::~Test()
{
}

void Test::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();

}

void Test::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();

}

void Test::process(
    
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

const char *Test::parameter_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "resetBtn";
    
    case 1:
        return "xVal";
    
    case 2:
        return "yVal";
    
    case 3:
        return "position";
    
    case 4:
        return "endpoint";
    
    default:
        return 0;
    }
}

const char *Test::parameter_short_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    case 3:
        return "";
    
    case 4:
        return "";
    
    default:
        return 0;
    }
}

const char *Test::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "resetBtn";
    
    case 1:
        return "xVal";
    
    case 2:
        return "yVal";
    
    case 3:
        return "position";
    
    case 4:
        return "endpoint";
    
    default:
        return 0;
    }
}

const char *Test::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    case 3:
        return "";
    
    case 4:
        return "";
    
    default:
        return 0;
    }
}

const Test::ParameterRange *Test::parameter_range(unsigned index) noexcept
{
    switch (index) {
    
    case 0: {
        static const ParameterRange range = { 0, 0, 1 };
        return &range;
    }
    
    case 1: {
        static const ParameterRange range = { 0, 0, 240000 };
        return &range;
    }
    
    case 2: {
        static const ParameterRange range = { 0, 0, 1 };
        return &range;
    }
    
    case 3: {
        static const ParameterRange range = { 0, 0, 1 };
        return &range;
    }
    
    case 4: {
        static const ParameterRange range = { 0, 0, 1 };
        return &range;
    }
    
    default:
        return 0;
    }
}

bool Test::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return true;
    
    default:
        return false;
    }
}

bool Test::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return true;
    
    default:
        return false;
    }
}

bool Test::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return true;
    
    default:
        return false;
    }
}

bool Test::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

float Test::get_parameter(unsigned index) const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        return dsp.fButton0;
    
    case 1:
        return dsp.fHslider1;
    
    case 2:
        return dsp.fHslider0;
    
    case 3:
        return dsp.fHbargraph0;
    
    case 4:
        return dsp.fHbargraph1;
    
    default:
        (void)dsp;
        return 0;
    }
}

void Test::set_parameter(unsigned index, float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        dsp.fButton0 = value;
        break;
    
    case 1:
        dsp.fHslider1 = value;
        break;
    
    case 2:
        dsp.fHslider0 = value;
        break;
    
    default:
        (void)dsp;
        (void)value;
        break;
    }
}


float Test::get_resetBtn() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fButton0;
}

float Test::get_xVal() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider1;
}

float Test::get_yVal() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}

float Test::get_position() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHbargraph0;
}

float Test::get_endpoint() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHbargraph1;
}


void Test::set_resetBtn(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fButton0 = value;
}

void Test::set_xVal(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider1 = value;
}

void Test::set_yVal(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}




