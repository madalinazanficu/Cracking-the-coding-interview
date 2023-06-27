#include <iostream>
#include <vector>

// O(b) time, b = number of bits, O(b) space

std::vector <int> subSeq(int n) {

    std::vector <int> seq;
    bool search_for = 0;
    int cnt = 0;
    while (n) {

        if ((n & 1) != search_for) {
            seq.push_back(cnt);
            cnt = 0;

            // flip the searchig value
            search_for = n & 1;
        }
        cnt++;
        n = n >> 1;
    }
    return seq;
}

int longestSeq(std::vector <int> &seq) {

    int maxSeq = 1;

    // the even (par) i => represent the 0s
    // the odd i => 1s

    for (int i = 0; i < seq.size(); i++) {

        int zeroSeq = seq[i];
        int onesSeqRight, onesSeqLeft;

        if (i == 0)
            onesSeqLeft = 0;
        else
            onesSeqLeft = seq[i - 1];

        if (i == seq.size() - 1)
            onesSeqRight = 0;
        else
            onesSeqRight = seq[i + 1];

        // merge the sequences
        int thisSeq = 0;

        if (zeroSeq == 1) {
            // could be merge
            thisSeq = 1 + onesSeqLeft + onesSeqRight;
        }
        if (zeroSeq > 1) {
            // just add 1 to either sides
            if (onesSeqRight > onesSeqLeft)
                thisSeq = onesSeqRight + 1;
            else
                thisSeq = onesSeqLeft + 1;
        }
        if (zeroSeq == 0) {
            // take the biggest of either sides
            if (onesSeqRight > onesSeqLeft)
                thisSeq = onesSeqRight;
            else
                thisSeq = onesSeqLeft + 1;
        }

        if (thisSeq > maxSeq) {
            maxSeq = thisSeq;
        }
    }
    return maxSeq;
}

int main() {

    int x;
    std::cin >> x;
    std::vector <int> seq = subSeq(x);
    std::cout << longestSeq(seq) << '\n';
    return 0;
}