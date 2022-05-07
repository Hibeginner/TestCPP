#ifndef __Calculator_H__
#define __Calculator_H__

#ifdef Calculator_EXPORT
#define DLLEXPORT __declspec(dllexport) //µ¼³ödllÉùÃ÷
#else
#define DLLEXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	DLLEXPORT int addFunc(int a, int b);

	typedef struct PathPlanInputForUnity {
		int PlanMode;
		double PlanStep;
		double Acc_des;
		double Vel_max;
		int PlanJoint;
		double Joint_ini[6];
		double Joint_des[6];
		double PEend_mid[6];
		double PEend_des[6];
	}INPUT_STRUCT;

	typedef struct PathPlanOutputForUnity {
		int totalstep;
		double plantime;
		double ResultJointVel[20000];
		double ResultJoint[20000];
		double endPE[20000];
	}OUTPUT_STRUCT;

	DLLEXPORT int _stdcall testDllStructAdd(INPUT_STRUCT* in, OUTPUT_STRUCT* out);
#ifdef __cplusplus
}
#endif // __cplusplus



class DLLEXPORT Calculator
{
public:
	int classAddFunc(int a, int b);
};

#endif