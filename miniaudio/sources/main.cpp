#include "Audio.h"

#include <stdio.h>
#include <iostream>

int main()
{
	AudioEngine audioEngine;
	audioEngine.Init();

	const char* filepath = "resources/audio.mp3";
	AudioSource audio(filepath);

	char input;
	float volume = 1.0f;
	while (true)
	{
		printf("Press p(Play) s(Stop) q(Exit) e(volUP) r(volDWN): ");

		input = getchar();
		if (input == 'p')
			audio.Play();
		else if (input == 's')
			audio.Stop();
		else if (input == 'q')
			break;

		else if (input == 'e')
			volume += 0.1f;
		else if (input == 'r')
			volume -= 0.1f;

		if (volume < 0.0f)
			volume = 0.0f;
		else if (volume > 1.0f)
			volume = 1.0f;

		audio.SetVolume(volume);
	}

	audioEngine.Shutdown();
	getchar();

	return 0;
}