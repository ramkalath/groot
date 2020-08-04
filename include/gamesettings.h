#pragma once

#include<chrono>

typedef std::chrono::high_resolution_clock::time_point TimeVar;
void calculate_fps(TimeVar *start, unsigned int *tmp_fps, unsigned int *fps)
{
		unsigned int duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-*start).count(); 
		(*tmp_fps)++;
		if(duration > 1000)
		{
			*fps = *tmp_fps;
			*tmp_fps = 0;
			*start = std::chrono::high_resolution_clock::now(); 
		}
		else
			*fps = 0;
}
