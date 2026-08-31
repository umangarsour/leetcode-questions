class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* p0 = head;
        ListNode* p1 = head->next;
        int idx = 1;
        int firstIdx = -1, lastIdx = -1, prevIdx = -1;
        int minDist = INT_MAX;

        while(p1->next != NULL){
            ListNode* p2 = p1->next;
            bool isMax = (p1->val > p0->val && p1->val > p2->val);
            bool isMin = (p1->val < p0->val && p1->val < p2->val);

            if(isMax || isMin){
                if(firstIdx == -1) firstIdx = idx;
                if(prevIdx != -1) minDist = min(minDist, idx - prevIdx);
                prevIdx = idx;
                lastIdx = idx;
            }

            p0 = p1;
            p1 = p2;
            idx++;
        }

        if(firstIdx == -1 || firstIdx == lastIdx) return {-1, -1};
        return {minDist, lastIdx - firstIdx};
    }
};