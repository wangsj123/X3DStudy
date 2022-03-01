#ifndef _GAMETIMER_H
#define _GAMETIMER_H

class GameTimer
{
public:
	GameTimer();
	float TotalTime() const;    //��ʱ��
	float DeltaTime() const;    //֡���ʱ��

	void Reset();   //��Ϣѭ��֮ǰ����
	void Start();   //ȡ����ͣ
	void Stop();    //��ͣ
	void Tick();    //ÿ֡����

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
