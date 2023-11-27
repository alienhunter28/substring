#include <iostream>
#include <vector>

std::string longestCommonSubstring(const std::string &str1, const std::string &str2) {
    int m = str1.length();
    int n = str2.length();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    int maxLength = 0;
    int endIndex = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    std::cout << "Lookup Table:\n";
    std::cout << "  ";
    for (int j = 0; j <= n; ++j) {
        if (j > 0) {
            std::cout << " " << str2[j - 1] << "";
        } else {
            std::cout << " ";
        }
    }
    std::cout << "\n";

    for (int i = 0; i <= m; ++i) {
        if (i > 0) {
            std::cout << str1[i - 1] << " ";
        } else {
            std::cout << "  ";
        }

        for (int j = 0; j <= n; ++j) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::string result = str1.substr(endIndex - maxLength + 1, maxLength);
    return result;
}

int main() {
    std::string str1, str2;
    std::cout << "Enter the first string: ";
    std::cin >> str1;
    std::cout << "Enter the second string: ";
    std::cin >> str2;

    if (str1.length() != str2.length()) {
        std::cerr << "Error: The input strings must have the same length.\n";
        return 1;
    }

    std::string lcs = longestCommonSubstring(str1, str2);
    std::cout << "Longest Common Substring: " << lcs << "\n";

    return 0;
}
