// refrence aditya verma
sabse pehle  hame pata kaise lagega left se traverse krna hai ya right se
uske liye ham bich ke kisi index pr khade hoke check krenge hame kis part me dekhna hai left ya fir right if it is right then we have to traverse from right or else from left
​
teen condition ho sakti hai for next greater
ya to stack khali hoga us case me -1 push krna hai
ya st.top() is greater than nums2[i] us case me ans st.top() hoga
ya fir st ka top chota hoga us case me pop krte rehna hai jab tak ki stack empty na ho jaye
ya fir jab tak stack ka top element nums[i] se chota hai
// fir check kr lena hai agr while loop stack empty ke vjh se braek hua hai then push -1 otherwise stack ka top greater hone ki vjh se break hua hai is case me push st.top()
// finally reverse the vector in case of nge
​
// agr next greater to left hai to left se traverse kro aur vector ko reverse nahi krna hai
// baki code same hai as of nge