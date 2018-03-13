/*
==============================================================================

This file was auto-generated by the Jucer!

It contains the basic startup code for a Juce application.

==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
SpectralDelayPluginAudioProcessorEditor::SpectralDelayPluginAudioProcessorEditor (SpectralDelayPluginAudioProcessor& p)
	: AudioProcessorEditor (&p), processor (p),
	//initialize the labels indicating what the sliders represent
	f0_titleLabel("Filter 0 title", "Filter 0 delay (mS)"),
	f1_titleLabel("Filter 1 title", "Filter 1 delay (mS)"),
	f2_titleLabel("Filter 2 title", "Filter 2 delay (mS)"),
	f3_titleLabel("Filter 3 title", "Filter 3 delay (mS)"),
	f4_titleLabel("Filter 4 title", "Filter 4 delay (mS)"),
	//initialize labels indicating name and version of plugin
	logo("Logo", "Spectral Filter Delay Bank"),
	version("Version Number", "v1.0 by David Smith 2012"),
	//initialize the sliders to control the delay amounts
	f0_delaySlider("Filter 0 delay slider"),
	f1_delaySlider("Filter 1 delay slider"),
	f2_delaySlider("Filter 2 delay slider"),
	f3_delaySlider("Filter 3 delay slider"),
	f4_delaySlider("Filter 4 delay slider")
{
	// This is where our plugin's editor size is set.
	setSize (300, 300);

	//set the bounds of the silders
	f0_delaySlider.setRange(0, SpectralDelayPluginAudioProcessor::maxTimeDelayInMs, 1);
	f1_delaySlider.setRange(0, SpectralDelayPluginAudioProcessor::maxTimeDelayInMs, 1);
	f2_delaySlider.setRange(0, SpectralDelayPluginAudioProcessor::maxTimeDelayInMs, 1);
	f3_delaySlider.setRange(0, SpectralDelayPluginAudioProcessor::maxTimeDelayInMs, 1);
	f4_delaySlider.setRange(0, SpectralDelayPluginAudioProcessor::maxTimeDelayInMs, 1);

	f0_delaySlider.setValue(0);
	f1_delaySlider.setValue(200);
	f2_delaySlider.setValue(250);
	f3_delaySlider.setValue(275);
	f4_delaySlider.setValue(300);

	f0_delaySlider.addListener(this);
	f1_delaySlider.addListener(this);
	f2_delaySlider.addListener(this);
	f3_delaySlider.addListener(this);
	f4_delaySlider.addListener(this);

	//define the top corner all the components will be placed relative to
	int xTop = 10;
	int yTop = 10;
	//define the spacing units used on each axis
	int yUnit = 20;
	int xUnit = 10;
	int textWidth = 150;
	int textHeight = 20;

	f0_titleLabel.setBounds(xTop, yTop, textWidth, textHeight);
	f0_delaySlider.setBounds(xTop + xUnit, yTop + yUnit, 260, 20);

	f1_titleLabel.setBounds(xTop, yTop + 2*yUnit, textWidth, textHeight);
	f1_delaySlider.setBounds(xTop + xUnit, yTop + 3*yUnit, 260, 20);

	f2_titleLabel.setBounds(xTop, yTop + 4*yUnit, textWidth, textHeight);
	f2_delaySlider.setBounds(xTop + xUnit, yTop + 5*yUnit, 260, 20);

	f3_titleLabel.setBounds(xTop, yTop + 6*yUnit, textWidth, textHeight);
	f3_delaySlider.setBounds(xTop + xUnit, yTop + 7*yUnit, 260, 20);

	f4_titleLabel.setBounds(xTop, yTop + 8*yUnit, textWidth, textHeight);
	f4_delaySlider.setBounds(xTop + xUnit, yTop + 9*yUnit, 260, 20);

	logo.setFont(Font(32, 2));
	logo.setBounds(xTop, yTop + 10*yUnit + 20, 260, 40);
	version.setFont(Font(15, 2));
	version.setBounds(xTop + 10, yTop + 12*yUnit + 10, 300, 30);

	addAndMakeVisible(&f0_titleLabel);
	addAndMakeVisible(&f1_titleLabel);
	addAndMakeVisible(&f2_titleLabel);
	addAndMakeVisible(&f3_titleLabel);
	addAndMakeVisible(&f4_titleLabel);

	addAndMakeVisible(&logo);
	addAndMakeVisible(&version);

	addAndMakeVisible(&f0_delaySlider);
	addAndMakeVisible(&f1_delaySlider);
	addAndMakeVisible(&f2_delaySlider);
	addAndMakeVisible(&f3_delaySlider);
	addAndMakeVisible(&f4_delaySlider);
}

SpectralDelayPluginAudioProcessorEditor::~SpectralDelayPluginAudioProcessorEditor()
{

}

//==============================================================================
void SpectralDelayPluginAudioProcessorEditor::paint (Graphics& g)
{
	g.fillAll (Colours::lightgrey);
	g.setColour (Colours::black);
	g.setFont (15.0f);
}
 void SpectralDelayPluginAudioProcessorEditor::resized(){};
void SpectralDelayPluginAudioProcessorEditor::sliderValueChanged(Slider* changedSlider)
{
	//the values stored on the sliders range from 0 - 2000 mS, so first convert the time quantity into samples
	//and then map the sample value to 0 - 1.0 as per the VST specification keeping in mind that maxSampleDelay = 2*Fs
	//value = (time * .001 * maxSampleDelay/2) / maxSampleDelay = (time * .001) / 2
	//SpectralDelayPluginAudioProcessor* audioProcessor = getProcessor();
	double value = (changedSlider->getValue() * .001) / 2; 

	if(changedSlider == &f0_delaySlider)
	{
		processor.setParameterNotifyingHost(SpectralDelayPluginAudioProcessor::f0_delayParam, value);
	}
	else if(changedSlider == &f1_delaySlider)
	{
		processor.setParameterNotifyingHost(SpectralDelayPluginAudioProcessor::f1_delayParam, value);
	}
	else if(changedSlider == &f2_delaySlider)
	{
		processor.setParameterNotifyingHost(SpectralDelayPluginAudioProcessor::f2_delayParam, value);
	}
	else if(changedSlider == &f3_delaySlider)
	{
		processor.setParameterNotifyingHost(SpectralDelayPluginAudioProcessor::f3_delayParam, value);
	}
	else if(changedSlider == &f4_delaySlider)
	{
		processor.setParameterNotifyingHost(SpectralDelayPluginAudioProcessor::f4_delayParam, value);
	}
}
