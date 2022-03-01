#include "GameTimer.h"
#include <Windows.h>

GameTimer::GameTimer() : m_secondsPerCount(0.0)
                       , m_deltaTime(-1.0)
                       , m_baseTime(0)
                       , m_stopTime(0)
                       , m_pausedTime(0)
                       , m_prevTime(0)
                       , m_currTime(0)
                       , m_bStopped(false)
{
    __int64 countsPerSec;
    QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
    m_secondsPerCount = 1.0 / (double)countsPerSec;
}

float GameTimer::TotalTime() const
{
    //                     |<--paused time-->|
    // ----*---------------*-----------------*------------*------------*------> time
    //  m_BaseTime       m_StopTime        startTime     m_StopTime    m_CurrTime
    if (m_bStopped)
    {
        return (float)(((m_stopTime - m_pausedTime)-m_baseTime)*m_secondsPerCount);
    }
    else
    {
        //  (m_CurrTime - m_PausedTime) - m_BaseTime 
        //
        //                     |<--paused time-->|
        // ----*---------------*-----------------*------------*------> time
        //  m_BaseTime       m_StopTime        startTime     m_CurrTime
        return (float)(((m_currTime - m_pausedTime) - m_baseTime) * m_secondsPerCount);
    }
    return 0.0f;
}

float GameTimer::DeltaTime() const
{
    return (float)m_deltaTime;
}

void GameTimer::Reset()
{
    __int64 currTime;
    QueryPerformanceCounter((LARGE_INTEGER*)&currTime);
    m_baseTime = currTime;
    m_prevTime = currTime;
    m_stopTime = 0;
    m_pausedTime = 0;
    m_bStopped = false;
}

void GameTimer::Start()
{
    __int64 startTime;
    QueryPerformanceCounter((LARGE_INTEGER*)&startTime);
    if (m_bStopped)
    {
        m_pausedTime += (startTime - m_stopTime);
        m_prevTime = startTime;
        m_stopTime = 0;
        m_bStopped = false;
    }
}

void GameTimer::Stop()
{
    if (!m_bStopped)
    {
        __int64 currTime;
        QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

        m_stopTime = currTime;
        m_bStopped = true;
    }
}

void GameTimer::Tick()
{
    if (m_bStopped)
    {
        m_deltaTime = 0.0;
        return;
    }

    __int64 currTime;
    QueryPerformanceCounter((LARGE_INTEGER*)&currTime);
    m_currTime = currTime;
    m_deltaTime = (m_currTime - m_prevTime) * m_secondsPerCount;

    m_prevTime = m_currTime;
    if (m_deltaTime < 0.0)
    {
        m_deltaTime = 0.0;
    }
}
