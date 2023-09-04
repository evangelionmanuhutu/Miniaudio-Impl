#include "Audio.h"

#include <stdio.h>
#include <iostream>

int main()
{
	AudioEngine audioEngine;
	if (audioEngine.Init() == false)
		return 0;

	AudioSource audioSource("resources/audio.mp3");

	char inp;
	float volume = 1.0f;
	float pan = 0.0f;

	while (true)
	{
		printf("Audio Volume : %.1f\n", volume);
		printf("Audio Panning: %.1f\n", pan);

		printf("P : Play\n");
		printf("S : Stop\n");
		printf("E : Increase Volume\n");
		printf("Q : Decrease Volume\n");
		printf("D : Panning to Right");
		printf("A : Panning to Left");
		printf("X : Exit\n");

		inp = getchar();
		system("cls");

		if (inp == 'x')
			break;

		if (inp == 'p')
			audioSource.Play();
		else if (inp == 's')
			audioSource.Stop();

		if (inp == 'e')
			volume += 0.1f;
		else if (inp == 'q')
			volume -= 0.1f;

		if (volume > 1.0f)volume = 1.0f;
		else if (volume < 0.0f) volume = 0.0f;

		audioSource.SetVolume(volume);

		if (inp == 'a')
			pan -= 0.1f;
		else if (inp == 'd')
			pan += 0.1f;

		audioSource.SetPan(pan);
	}

	audioEngine.Shutdown();
	return 0;
}