class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_set = {}
        t_set = {}

        for c in s:
            if c in s_set:
                s_set[c] += 1
            else:
                s_set[c] = 0

        for c in t:
            if c in t_set:
                t_set[c] += 1
            else:
                t_set[c] = 0

        if s_set == t_set:
            return True
        else:
            return False


