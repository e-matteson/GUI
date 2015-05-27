/*
  ==============================================================================

    MyTestThread.h
    Created: 27 May 2015 5:41:29am
    Author:  em

  ==============================================================================
/*
    ------------------------------------------------------------------

    This file is part of the Open Ephys GUI
    Copyright (C) 2014 Open Ephys

    ------------------------------------------------------------------

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef MYTESTTHREAD_H_INCLUDED
#define MYTESTTHREAD_H_INCLUDED

#include "../../../JuceLibraryCode/JuceHeader.h"

#include <stdio.h>
#include <time.h>
#include "DataThread.h"

class SourceNode;

/**

  Fills a buffer with data from a file.

  Has issues with setting the correct sampling rate.

  @see DataThread

*/

class FileReaderThread : public DataThread

{
public:
    FileReaderThread(SourceNode* sn);
    ~FileReaderThread();

    bool startAcquisition();
    bool stopAcquisition();
    float getSampleRate();


private:
    float thisSample[16];
    int16 readBuffer[1600];

    int bufferSize;

    String filePath;

    /* bool updateBuffer(); */

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FileReaderThread);
};








#endif  // MYTESTTHREAD_H_INCLUDED
