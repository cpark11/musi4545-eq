/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginParameter.h"
#include "BiQuad.h"
#include "Mu45FilterCalc.h"


//==============================================================================
/**
*/
class Mu45effectAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    Mu45effectAudioProcessor();
    ~Mu45effectAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    //Mu45Param: Add a pointer for each user parameter
    PluginParameter* volumeUParam;
	PluginParameter* lowshelfcutUparam;
	PluginParameter* lowshelfgainUparam;
	PluginParameter* highshelfcutUparam;
	PluginParameter* highshelfgainUparam;
	PluginParameter* notchcutUparam;
	PluginParameter* notchgainUparam;
	PluginParameter* notchQUparam;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Mu45effectAudioProcessor)
    
    //Mu45: Create any methods you will need
    void calcAlgorithmParams();
    
    //Mu45: Create other variables you will need, such as algorithm parameters
    float gainAParam;      // The linear gain to be applied
	float sampRate;
	float lowshelfcutAparam; //low shelf cut algorithmic parameter
	float lowshelfgainAparam; //low shelf gain algorithmic parameter
	float highshelfcutAparam;	
	float highshelfgainAparam;
	float notchcutAparam;
	float notchgainAparam;
	float notchQAparam;

	stk::BiQuad lowshelfFilterL, lowshelfFilterR, highshelfFilterL, highshelfFilterR, notchFilterL, notchFilterR;
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
