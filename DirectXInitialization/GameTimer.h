#ifndef _GAMETIMER_H
#define _GAMETIMER_H

class GameTimer
{
public:
	GameTimer();
	float TotalTime() const;    //总时间
	float DeltaTime() const;    //帧间隔时间

	void Reset();   //消息循环之前调用
	void Start();   //取消暂停
	void Stop();    //暂停
	void Tick();    //每帧调用

private:
	double m_secondsPerCount;
	double m_deltaTime;

	__int64 m_baseTime;
	__int64 m_pausedTime;
	__int64 m_stopTime;
	__int64 m_prevTime;
	__int64 m_currTime;

	bool m_bStopped;
};

#endif
