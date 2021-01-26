class Solution:
    def isNumber(self, s: str) -> bool:
        pattern = re.compile('(^\\s*)[-+]?(\\d+\\.?|\\.\\d+)\\d*(e[-+]?\\d+)?(\\s*$)')
        return None != re.match(pattern, s)