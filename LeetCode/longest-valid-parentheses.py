class Solution:
    def longestValidParentheses(self, s: str) -> int:
        from queue import LifoQueue
        
        st = LifoQueue(maxsize=len(s) + 1)
        ans, val = 0, 0
        di = { 0 : -1 }
    
        st.put(0)
        for  i, ch in enumerate(s):
            val = val + (1 if ch == '(' else -1)
            
            while not st.empty():
                top  = st.get()
                if top <= val:
                    st.put(top)
                    break
                di[top] = -2
            st.put(val)
            
            if val not in di or di[val] == -2:
                di[val] = i
                
            if val in di:
                ans = max(ans, i - di[val])
            
        return ans
