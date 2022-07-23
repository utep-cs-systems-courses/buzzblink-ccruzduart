#ifndef buzzer_included
#define buzzer_included

void buzzer_init();
void buzzer_set_period();
void updateCycles();
void buzzerOff();
void updateCyclesFaster();
void buzzer_set_period2(short cycles2);

//musical notes
#define tuned 2000000
#define C_3 132.60
#define C_s3 140.28
#define D_3 148.83
#define E_3 167.06
#define F_3 177.00
#define F_s3 187.52
#define G_3 198.67
#define G_s3 210.48
#define A_3 223.00
#define A_s3 236.26
#define B_3 250.31
#define C_4 265.19
#define C_s4 280.96
#define D_4 297.67
#define D_s4 315.37
#define E_4 334.12
#define F_4 353.99
#define F_s4 353.99
#define G_4 397.34
#define G_s4 420.97
#define A_4 446
#define B_4 500.62
#define C_5 530.39
#define C_s5 530.39
#define D_5 595.34
#define D_s5 630.74
#define E_5 668.24
#define F_5 707.98
#define F_s5 750.08
#define G_5 794.68
#define G_s5 841.94
#define A_5 892
#define A_s5 945.04
#define B_5 1001.24
#define C_6 1060.77
#define C_s6 1123.85
#define D_6 1190.68
#define E_6 1336.49
#define F_6 1415.96
#define F_s6 1500.16
#endif
