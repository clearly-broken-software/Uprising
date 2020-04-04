
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






#pragma once
#ifndef Test_Faust_pp_Gen_HPP_
#define Test_Faust_pp_Gen_HPP_

#include <memory>

class Test {
public:
    Test();
    ~Test();

    void init(float sample_rate);
    void clear() noexcept;

    void process(
        
        float *out0,float *out1,
        unsigned count) noexcept;

    enum { NumInputs = 0 };
    enum { NumOutputs = 2 };
    enum { NumActives = 3 };
    enum { NumPassives = 2 };
    enum { NumParameters = 5 };

    enum Parameter {
        p_resetBtn,
        p_xVal,
        p_yVal,
        p_position,
        p_endpoint,
        
    };

    struct ParameterRange {
        float init;
        float min;
        float max;
    };

    static const char *parameter_label(unsigned index) noexcept;
    static const char *parameter_short_label(unsigned index) noexcept;
    static const char *parameter_symbol(unsigned index) noexcept;
    static const char *parameter_unit(unsigned index) noexcept;
    static const ParameterRange *parameter_range(unsigned index) noexcept;
    static bool parameter_is_trigger(unsigned index) noexcept;
    static bool parameter_is_boolean(unsigned index) noexcept;
    static bool parameter_is_integer(unsigned index) noexcept;
    static bool parameter_is_logarithmic(unsigned index) noexcept;

    float get_parameter(unsigned index) const noexcept;
    void set_parameter(unsigned index, float value) noexcept;

    
    float get_resetBtn() const noexcept;
    
    float get_xVal() const noexcept;
    
    float get_yVal() const noexcept;
    
    float get_position() const noexcept;
    
    float get_endpoint() const noexcept;
    
    
    void set_resetBtn(float value) noexcept;
    
    void set_xVal(float value) noexcept;
    
    void set_yVal(float value) noexcept;
    

public:
    class BasicDsp;

private:
    std::unique_ptr<BasicDsp> fDsp;



};




#endif // Test_Faust_pp_Gen_HPP_
