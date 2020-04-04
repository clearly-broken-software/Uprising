
#include "DistrhoPluginInfo.h"
#include "DistrhoPlugin.hpp"
#include "Test.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

class UprisingPlugin : public Plugin
{
public:
    UprisingPlugin()
        : Plugin(1, 0, 0)
    {

        sr = getSampleRate();
        test.init(sr);
    }

protected:
    const char *getLabel() const override
    {
        return "Uprising";
    }

    const char *getDescription() const override
    {
        return "Transition Designer Synth";
    }

    const char *getMaker() const override
    {
        return "Clearly Broken Software";
    }

    const char *getHomePage() const override
    {
        return "https://github.com/clearly-broken-software/uprising";
    }

    const char *getLicense() const override
    {
        return "ISC";
    }

    uint32_t getVersion() const override
    {
        return d_version(0, 0, 1);
    }

    int64_t getUniqueId() const override
    {
        return d_cconst('u', 'P', 'r', 'i');
    }

    void initParameter(uint32_t index, Parameter &parameter) override
    {
        switch (index)
        {
        case kResetBtn:
            parameter.name = "ResetBtn";
            parameter.ranges.def = 0;
            parameter.ranges.min = 0;
            parameter.ranges.max = 1;
            parameter.hints = kParameterIsAutomable || kParameterIsInteger;
            parameter.symbol = "resetbtn";
            break;
        case kXval:
            parameter.name = "Xval";
            parameter.symbol = "xval";
            parameter.ranges.def = 0;
            parameter.ranges.min = 1;
            parameter.ranges.max = 5 * 48000;
            parameter.hints = kParameterIsAutomable || kParameterIsInteger;
            break;
        case kYval:
            parameter.name = "Yval";
            parameter.symbol = "yval";
            parameter.ranges.def = 0;
            parameter.ranges.min = 0;
            parameter.ranges.max = 1;
            parameter.hints = kParameterIsAutomable;
            break;
        case kPosition:
            parameter.name = "Position";
            parameter.symbol = "position";
            parameter.ranges.def = 0;
            parameter.ranges.min = 0;
            parameter.ranges.max = 1;
            parameter.hints = kParameterIsOutput;
        case kEndPoint:
            parameter.name = "EndPoint";
            parameter.symbol = "endpoint";
            parameter.ranges.def = 0;
            parameter.ranges.min = 0;
            parameter.ranges.max = 1;
            parameter.hints = kParameterIsOutput;
        default:
            printf("unexpected parmater");
            break;
        }
    }

    float getParameterValue(uint32_t index) const override
    {
        switch (index)
        {
        case kResetBtn:
            return test.get_resetBtn();
            break;
        case kXval:
            return test.get_xVal();
            break;
        case kYval:
            return test.get_yVal();
            break;
        case kPosition:
            return test.get_position();
            break;
        case kEndPoint:
            return test.get_endpoint();
        default:
            return 0.0f;
            break;
        }
    }

    void setParameterValue(uint32_t index, float value) override
    {
        switch (index)
        {
        case kResetBtn:
            test.set_resetBtn(value);
            break;
        case kXval:
            test.set_xVal(value);
            break;
        case kYval:
            test.set_yVal(value);
            break;
        default:
            break;
        }
    }

    void run(const float **, float **outputs, uint32_t frames) override
    {
        test.process(outputs[0], outputs[1], frames);
    }

private:
    float fParameters[parameterCount];

    Test test;

    double sr;
    float fResetBtn, fXval, fYval, fPosition, fEndPoint;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UprisingPlugin)
};

Plugin *createPlugin()
{
    return new UprisingPlugin();
}

END_NAMESPACE_DISTRHO
