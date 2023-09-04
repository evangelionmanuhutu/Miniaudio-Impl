#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio/miniaudio.h"
#include "Audio.h"

#include <vector>

AudioEngine* AudioEngine::s_Instance = nullptr;

AudioEngine::AudioEngine()
{
	s_Instance = this;
}

bool AudioEngine::Init()
{
	m_EngineConfig = ma_engine_config_init();
	m_EngineConfig.noDevice = MA_FALSE;
	m_EngineConfig.channels = 2;
	m_EngineConfig.sampleRate = 41000;

	if (ma_engine_init(&m_EngineConfig, &m_Engine) != MA_SUCCESS)
	{
		printf("AudioEngine: Failed to Initializing Miniaudio Engine\n");
		return false;
	}

	printf("AudioEngine: Initialized\n");

	return true;
}

void AudioEngine::Shutdown()
{
	ma_engine_uninit(&m_Engine);
	printf("AudioEngine: Shutdown\n");
}

AudioSource::AudioSource(std::string filepath, bool spatializing)
	: m_Filepath(filepath)
{
	if (ma_sound_init_from_file(&AudioEngine::Get().GetEngine(), filepath.c_str(),
		0, nullptr, nullptr, &m_Sound) != MA_SUCCESS)
	{
		printf("AudioSource: Failed to Load File: %s\n", filepath.c_str());
		return;
	}

	printf("AudioSource: Sound %s Loaded\n", filepath.c_str());
}

AudioSource::~AudioSource()
{
	ma_sound_uninit(&m_Sound);
}

void AudioSource::Play()
{
	printf("AudioSource: Playing %s\n", m_Filepath.c_str());
	ma_sound_start(&m_Sound);
}

void AudioSource::Stop()
{
	printf("AudioSource: Stopped %s\n", m_Filepath.c_str());
	ma_sound_stop(&m_Sound);
}

void AudioSource::SetVolume(float volume)
{
	m_Volume = volume;
	ma_sound_set_volume(&m_Sound, volume);
}

void AudioSource::SetPan(float pan)
{
	m_Pan = pan;
	ma_sound_set_pan(&m_Sound, pan);
}

void AudioSource::SetPosition(float x, float y, float z)
{
	ma_sound_set_position(&m_Sound, x, y, z);
}
