#pragma once
#include "miniaudio/miniaudio.h"

class AudioEngine
{
public:
	AudioEngine();

	void Init();
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
	AudioSource(const char* filepath, bool spatilazing = false);
	~AudioSource();

	void Play();
	void Stop();
	void SetVolume(float volume);

private:
	const char* m_Filepath = "";
	ma_sound m_Sound;
	float m_Volume = 1.0f;
};

class AudioListener
{
public:

private:
};