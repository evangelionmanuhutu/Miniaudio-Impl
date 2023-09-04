#pragma once
#include "miniaudio/miniaudio.h"

#include <string>

class AudioEngine
{
public:
	AudioEngine();

	bool Init();
	void Shutdown();

	static AudioEngine* s_Instance;
	static AudioEngine& Get() { return *s_Instance; }

	ma_engine& GetEngine() { return m_Engine; }

private:
	ma_engine m_Engine;
	ma_engine_config m_EngineConfig;
};

class AudioSource
{
public:
	AudioSource(std::string filepath, bool spatilazing = false);
	~AudioSource();

	void Play();
	void Stop();
	void SetVolume(float volume);
	void SetPan(float panning);
	void SetPosition(float x, float y, float z);

	const std::string& GetFilepath() { return m_Filepath; }

private:
	std::string m_Filepath;

	ma_sound m_Sound;
	float m_Volume = 1.0f;

	// center panning
	float m_Pan = 0.0f;
};

class AudioListener
{
public:

private:
};