class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        ans = 0
        allowed = set(allowed)
        for s in words:
            for c in s:
                if c not in allowed:
                    break
            else:
                ans += 1
        return ans