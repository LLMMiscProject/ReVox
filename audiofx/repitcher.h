#ifndef REPITCHER_H
#define REPITCHER_H

#include "iaudiofx.h"
#include "lib/pitchshift/pitchshift.h"

class Repitcher : public IAudioFX
{
public:
    Repitcher(std::shared_ptr<PitchShift> ps);

    void Process(float *buf) override;
    void Reset() override;
    float Get(std::string item) override;
    void Set(std::string item, int val) override;
    bool GetEnabled() override;
    void SetEnabled(bool enabled) override;

private:
    std::shared_ptr<PitchShift> ps;
};

#endif // REPITCHER_H
