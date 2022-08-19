public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> notPlacedCount;     // entry = {num, count of unplaced nums}
        unordered_map<int, int> sequenceEndCount;   // entry = {num, count of sequences ending at num}

        for (int num : nums) notPlacedCount[num]++;

        for (int num : nums) {
            bool alreadyContains = notPlacedCount[num] == 0;
            bool canAddToExisting = sequenceEndCount[num - 1] > 0;
            bool canAddNewSequence = notPlacedCount[num + 1] > 0 && notPlacedCount[num + 2] > 0;

            if (alreadyContains)
                continue;

            if (canAddToExisting) {
                notPlacedCount[num]--;
                sequenceEndCount[num - 1]--;
                sequenceEndCount[num]++;
            }

            else if (canAddNewSequence) {
                notPlacedCount[num]--;
                notPlacedCount[num + 1]--;
                notPlacedCount[num + 2]--;
                sequenceEndCount[num + 2]++;
            }

            else
                return false;
        }
        return true; 
    }