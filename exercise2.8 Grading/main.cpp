//描述：
//	Grading hundreds of thousands of Graduate Entrance Exams is a hard work.
//	It is even harder to design a process to make the results as fair as possible.
//	One way is to assign each exam problem to 3 independent experts.
//	If they do not agree to each other, a judge is invited to make the final decision.
//	Now you are asked to write a program to help this process.
//	For each problem, there is a full - mark P and a tolerance T(< P) given.
//	The grading rules are : 
//	• A problem will first be assigned to 2 experts, to obtain G1 and G2.
//	If the difference is within the tolerance, that is, if | G1 - G2 | ≤ T, this problem's grade will be the average of G1 and G2.     
//	• If the difference exceeds T, the 3rd expert will give G3.     
//	• If G3 is within the tolerance with either G1 or G2, but NOT both, then this problem's grade will be the average of G3 and the closest grade.
//	• If G3 is within the tolerance with both G1 and G2, then this problem's grade will be the maximum of the three grades.     
//	• If G3 is within the tolerance with neither G1 nor G2, a judge will give the final grade GJ.
//输入描述：
//	Each input file may contain more than one test case.
//	Each case occupies a line containing six positive integers : P, T, G1, G2, G3, and GJ, as described in the problem.
//	It is guaranteed that all the grades are valid, that is, in the interval[0, P].
//输出描述：
//	For each test case you should output the final grade of the problem in a line.The answer must be accurate to 1 decimal place.
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	int P;
	while (cin >> P)
	{
		int T, G1, G2, G3, GJ;
		cin >> T >> G1 >> G2 >> G3 >> GJ;
		double grade = 0;
		if (abs(G1 - G2) <= T)
		{
			grade = (G1 + G2) / 2.0;
		}
		else if (abs(G1 - G3) <= T && abs(G2 - G3) <= T)
		{
			grade = max(max(G1, G2), G3);
		}
		else if (abs(G1 - G3) <= T || abs(G2 - G3) <= T)
		{
			grade = abs(G1 - G3) >= abs(G2 - G3) ?
				(G2 + G3) / 2.0 : (G1 + G3) / 2.0;
		}
		else
		{
			grade = GJ;
		}
		cout << setiosflags(ios::fixed) << setprecision(1) <<
			grade << endl;
	}
}