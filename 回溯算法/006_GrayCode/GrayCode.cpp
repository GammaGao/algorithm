/* TITLE: Gray Code(¸ñÀ×Âë)
 *		The gray code is a binary numeral system where two successive values differ in only one bit.
 *		Given a non-negative integer n representing the total number of bits in the code, print the
 *		sequence of gray code. A gray code sequence must begin with 0.
 *		For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
		00 - 0
		01 - 1
		11 - 3
		10 - 2
 *		Note:
 *		For a given n, a gray code sequence is not uniquely defined.
 *		For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 *		For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 *
 * TIME:2015-5-21
 * TYPE:backtracking
 * AUTHOR:PengSc
 */
#include <iostream>
#include <vector>
using namespace std;

/* Gray Code: one method of gerneration is, for example n = 1,
		0	
	----------
		1

	n = 2, 
		0|0
		0|1
    ----------
		1|1
		1|0

	n = 3,
		0|00
		0|01
		0|11
		0|10
	----------
		1|10
		1|11
		1|01
		1|00
 */
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res;
		if (n == 0){
			res.push_back(0);
			return res;
		}
		res.push_back(0);
		res.push_back(1);
		for (int i = 1; i < n; i++){
			for (int j = pow(2, i) - 1; j >= 0; j--)
			res.push_back(res[j] | (1 << i));
		}
		return res;
	}
};

int main()
{
	Solution sl;
	vector<int> res;
	res = sl.grayCode(0);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
}