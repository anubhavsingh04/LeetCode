// min no of deletion: len(str1)-len(lcs)
// min no of insertion: len(str2)-len(lcs)
// those character which are not in LCS but in str1--> they need to be removed len(str1)-len(lcs)
// those character which are not in LCS but in str2--> they need to be removed len(str2)-len(lcs)
// s1=heap s2=pea   heap ko ea me convert krne ke liye 2 deletion lagenge
// then ea ko pea me convert krne ke liye ek insertion lagenge
​