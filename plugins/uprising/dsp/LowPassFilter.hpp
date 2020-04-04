
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






#pragma once
#ifndef LowPassFilter_Faust_pp_Gen_HPP_
#define LowPassFilter_Faust_pp_Gen_HPP_

#include <memory>

class LowPassFilter {
public:
    LowPassFilter();
    ~LowPassFilter();

    void init(float sample_rate);
    void clear() noexcept;

    void process(
        const float *in0,
        float *out0,
        unsigned count) noexcept;

    enum { NumInputs = 1 };
    enum { NumOutputs = 1 };
    enum { NumActives = 3 };
    enum { NumPassives = 0 };
    enum { NumParameters = 3 };

    enum Parameter {
        p_lpfGain,
        p_lpfQ,
        p_lpfCuttoff,
        
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

    
    float get_filterGain() const noexcept;
    
    float get_lpQ() const noexcept;
    
    float get_lpfCuttoff() const noexcept;
    
    
    void set_filterGain(float value) noexcept;
    
    void set_lpQ(float value) noexcept;
    
    void set_lpfCuttoff(float value) noexcept;
    

public:
    class BasicDsp;

private:
    std::unique_ptr<BasicDsp> fDsp;



};




#endif // LowPassFilter_Faust_pp_Gen_HPP_
