#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

void task_first();
void task_second();
void task_third();
void task_forth();
void task_fifth();
void task_sixth();

// в некоторых задачах при переводе в int я не прибавляю к значению 0.5, т.к в таком случае у меня не в лучшую сторону
// меняется точность
void main()
{
	/* Выберите функцию для использования */
	task_second();
}

void task_first()
{
	float g, m, s;
	cout << "Enter the angle value (angle minutes seconds): ";
	cin >> g >> m >> s;
	int sign = ((int)(g) >> 31) & 1;
	m = (sign ^ 1) * m - sign * m;
	s = (sign ^ 1) * s - sign * s;
	float angle = g + m / 60.0 + s / 3600.0;
	float answer = angle / 180 * M_PI;
	cout << "Radian value: " << answer;
}

void task_second()
{
	float r, alpha, angle, minutes, seconds;
	cout << "Enter the radian value: ";
	cin >> r;
	int sign = ((int)(r) >> 31) & 1;
	alpha = r * 180.0 / M_PI;
	angle = (int)(alpha) % 360;
	minutes = (sign ^ 1) * (int)(alpha * 60) % 60 - sign * (int)(alpha * 60) % 60;
	seconds = (sign ^ 1) * (int)(alpha * 3600) % 60 - sign * (int)(alpha * 3600) % 60;
	cout << "Angle: " << " " << angle << " " << minutes << " " << seconds;
}

void task_third()
{
	float k, p, s, all_months;
	int years, months;
	cout << "Enter the capital, the percentage of profit and the amount of accumulation (number percent number): ";
	cin >> k >> p >> s;
	all_months = log(s / k) / log(p / 100.0 + 1.0);
	years = (int)(all_months + 0.5) / 12;
	months = (int)(all_months + 0.5) - years * 12;
	cout << "You will accumulate the required amount for " << years << " years and " << months << " months";
}

void task_forth()
{
	float a, b, c;
	cout << "Enter a, b, c ratios (a b c):";
	cin >> a >> b >> c;
	float x0, y0;
	x0 = -b / 2 / a;
	y0 = a * x0 * x0 + b * x0 + c;
	cout << "y0 = " << y0;
}

void task_fifth()
{
	float h, m, s;
	cout << "Enter time (hh mm ss): ";
	cin >> h >> m >> s;
	float time = s + m * 60 + h * 3600;
	cout << "Rounded time: " << (int)(time / 3600.0 + 0.5) << ":" << (int)(time / 60.0 + 0.5) % 60 << " or " << (int)(time / 3600.0 + 0.5) << " hours";
	/*23 59 59*/
}

void task_sixth()
{
	double r, a;
	cout << "Enter the radius of the circle and the side of triangle (r a): ";
	cin >> r >> a;
	// посчитаю сторону правильного треугольника описанного у окружности
	double a_the_described_triangle = 6 * r / sqrt(3);
	// отниму одну сторону описанного треугольника из основания данного треугольника, чтобы убедиться, что в углы треугольнька можно вписать по окружности
	double count_of_triangles_in_base_of_triangle = (int)((a - a_the_described_triangle - 2 * r) / 2 / r + 2 + 0.5);
	float answer = (1 + count_of_triangles_in_base_of_triangle) / 2 * count_of_triangles_in_base_of_triangle;
	cout << "You will be able to cut: " << answer << " circles";
}
