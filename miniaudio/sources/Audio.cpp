#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio/miniaudio.h"
#include "Audio.h"

#include <vector>

AudioEngine* AudioEngine::s_Instance = nullptr;

AudioEngine::AudioEngine()
{
	s_Instance = this;
}

void AudioEngine::Init()
{
	m_EngineConfig = ma_engine_config_init();
	m_EngineConfig.noDevice = MA_TRUE;
	m_EngineConfig.channels = 2;
	m_EngineConfig.sampleRate = 48000;

	if (ma_engine_init(&m_EngineConfig, &m_Engine) != MA_SUCCESS)
	{
		printf("AudioEngine: Failed to Initializing Miniaudio Engine");
		return;
	}
	printf("AudioEngine: Initialized\n");
}

void AudioEngine::Shutdown()
{
	ma_engine_uninit(&m_Engine);
	printf("AudioEngine: Shutdown\n");
}

AudioSource::AudioSource(const char *filepath, bool spatializing) : m_Filepath(filepath)
{
	ma_spatializer spatializer;


	if (ma_sound_init_from_file(&AudioEngine::Get().GetEngine(), filepath, 0, nullptr, nullptr, &m_Sound) != MA_SUCCESS)
	{
		printf("AudioSource: Failed to Load File: %s\n", filepath);
		return;
	}

	printf("AudioSource: Sound %s Loaded\n", filepath);
}

AudioSource::~AudioSource()
{
	ma_sound_uninit(&m_Sound);
}

void AudioSource::Play()
{
	printf("AudioSource: Playing %s\n", m_Filepath);
	ma_sound_start(&m_Sound);
}

void AudioSource::Stop()
{
	printf("AudioSource: Stopped %s\n", m_Filepath);
	ma_sound_stop(&m_Sound);
}

void AudioSource::SetVolume(float volume)
{
	m_Volume = volume;
	ma_sound_set_volume(&m_Sound, volume);
}
