#include <iostream>
#include <algorithm>

bool valid(std::string a, std::string b) {
	if (a == b) return 1;
	if (b[0] == 'A' && b[b.size() - 1] == 'B') return 0;
	if (a.size() >= b.size()) return 0;

	bool ret = 0;
	if (b[b.size() - 1] == 'A') ret |= valid(a, b.substr(0, b.size() - 1));
	if (b[0] == 'B') {
		std::reverse(b.begin(), b.end());
		ret |= valid(a, b.substr(0, b.size() - 1));
	}
	return ret;
}

int main() {
	std::string a, b;
	std::cin >> a >> b;
	std::cout << valid(a, b) << std::endl;
	return 0;
}
