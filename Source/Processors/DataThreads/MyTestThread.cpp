/*
  ==============================================================================

    MyTestThread.cpp
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

#include "../SourceNode/SourceNode.h"
#include "MyTestThread.h"

MyTestThread::MyTestThread(SourceNode* sn) :
    DataThread(sn), lengthOfInputFile(0), input(0), bufferSize(0)
{

    bufferSize = 1600;
    dataBuffer = new DataBuffer(16, bufferSize*3);

    eventCode = 0;

    std::cout << "Test Thread initialized." << std::endl;

}

MyTestThread::~MyTestThread()
{
    if (input)
        fclose(input);
}

// void MyTestThread::setFile(String fullpath)
// {
// }
 //    filePath = fullpath;

//     const char* path = filePath.getCharPointer();

//     if (input)
//         fclose(input);

//     input = fopen(path, "r");

//     // Avoid a segfault if file isn't found
//     if (!input)
//     {
//         std::cout << "Can't find data file "
//                   << '"' << path << "\""
//                   << std::endl;
//         return;
//     }

//     fseek(input, 0, SEEK_END);
//     lengthOfInputFile = ftell(input);
//     rewind(input);


//     sn->tryEnablingEditor();

// }

// String MyTestThread::getFile()
// {
//   return ""//filePath;
// }

bool MyTestThread::foundInputSource()
{
    return input != 0;
}

int MyTestThread::getNumChannels()
{
    return 16;
}

float MyTestThread::getSampleRate()
{
    return 28000.0f;
}

float MyTestThread::getBitVolts()
{
    return 0.0305f;
}

bool MyTestThread::startAcquisition()
{
    if (!input)
        return false;

    startThread();
    return true;
}

bool MyTestThread::stopAcquisition()
{
    std::cout << "MyTestThread received disable signal." << std::endl;
    if (isThreadRunning())
    {
        signalThreadShouldExit();
    }

    return true;
}

bool MyTestThread::updateBuffer()
{
    // if (!input)
        // return false;
    // if (dataBuffer->getNumSamples() < bufferSize)

    //     for (int n = 0; n < bufferSize; n++)
    //     {
    //         thisSample[chan] = 42.0f

    //         if (chan == 15)
    //         {

    //             timestamp++; // = (0 << 0) + (0 << 8) + (0 << 16) + (0 << 24); // +
    //             //(4 << 32); // + (3 << 40) + (2 << 48) + (1 << 56);

    //             //timestamp++; // = timer.getHighResolutionTicks();
    //             dataBuffer->addToBuffer(thisSample, &timestamp, &eventCode, 1);
    //             chan = 0;
    //         }
    //         else
    //         {
    //             chan++;
    //         }


    //     }

    // }
    // else
    // {
    //     wait(50); // pause for 50 ms to decrease sample rate
    // }

    return true;
}


// MyTestThread::MyTestThread(SourceNode* sn) :
//   DataThread(sn), input(0), bufferSize(0)
// {

//     bufferSize = 1600;
//     dataBuffer = new DataBuffer(16, bufferSize*3);

//     eventCode = 0;

//     std::cout << "Test Thread initialized." << std::endl;

// }

// MyTestThread::~MyTestThread()
// {
// }

// bool MyTestThread::startAcquisition()
// {
//     // if (!input)
//         // return false;

//     startThread();
//     return true;
// }

// bool MyTestThread::stopAcquisition()
// {
//     std::cout << "test thread received disable signal." << std::endl;
//     if (isThreadRunning())
//     {
//         signalThreadShouldExit();
//     }

//     return true;
// }

// bool MyTestThread::foundInputSource()
// {
//     return input != 0;
// }


// int MyTestThread::getNumChannels()
// {
//     return 1;
// }

// float MyTestThread::getSampleRate()
// {
//     return 2.0f;
// }

// float MyTestThread::getBitVolts(int chan)
// {
//     return 0.0305f;
// }













// // bool MyTestThread::updateBuffer()
// // {
// //     if (!input)
// //         return false;
// //     if (dataBuffer->getNumSamples() < bufferSize)
// //     {
// //         //       // std::cout << dataBuffer->getNumSamples() << std::endl;

// //         if (ftell(input) >= lengthOfInputFile - bufferSize)
// //         {
// //             rewind(input);
// //         }

// //         size_t numRead = fread(readBuffer, 2, bufferSize, input);

// //         if (numRead != bufferSize)
// //         {
// //             std::cout << "Fewer samples read than were requested." << std::endl;
// //         }
        
// //         int chan = 0;

// //         for (int n = 0; n < bufferSize; n++)
// //         {
// //             thisSample[chan] = float(-readBuffer[n]) * 0.0305; // previously 0.035

// //             if (chan == 15)
// //             {

// //                 timestamp++; // = (0 << 0) + (0 << 8) + (0 << 16) + (0 << 24); // +
// //                 //(4 << 32); // + (3 << 40) + (2 << 48) + (1 << 56);

// //                 //timestamp++; // = timer.getHighResolutionTicks();
// //                 dataBuffer->addToBuffer(thisSample, &timestamp, &eventCode, 1);
// //                 chan = 0;
// //             }
// //             else
// //             {
// //                 chan++;
// //             }


// //         }

// //     }
// //     else
// //     {
// //         wait(50); // pause for 50 ms to decrease sample rate
// //     }

// //     return true;
// // }


