class Solution:
    def defangIPaddr(self, address: str) -> str:
        ret = address.replace(".", "[.]")
        return (ret)