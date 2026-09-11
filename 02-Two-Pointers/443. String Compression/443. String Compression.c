1int compress(char* chars, int charsSize) {
2    if (charsSize == 1) {
3        return 1;
4    }
5    int last_pos = 0;
6    int count = 1;
7
8    for (int i = 1; i < charsSize; i++) {
9        if (chars[i] == chars[i - 1]) {
10            count++;
11        } else {
12            chars[last_pos++] = chars[i - 1];
13
14            if (count > 1) {
15                int start = last_pos;
16
17                while (count != 0) {
18                    chars[last_pos++] = (count % 10) + '0';
19                    count /= 10;
20                }
21
22                int end = last_pos - 1;
23
24                while (start < end) {
25                    char temp = chars[start];
26                    chars[start] = chars[end];
27                    chars[end] = temp;
28                    start++;
29                    end--;
30                }
31
32                count = 1;
33            }
34        }
35    }
36
37    chars[last_pos++] = chars[charsSize-1];
38
39    if (count > 1) {
40        int start = last_pos;
41
42        while (count != 0) {
43            chars[last_pos++] = (count % 10) + '0';
44            count /= 10;
45        }
46
47        int end = last_pos - 1;
48
49        while (start < end) {
50            char temp = chars[start];
51            chars[start++] = chars[end];
52            chars[end--] = temp;
53        }
54
55        count = 1;
56    }
57
58    return last_pos;
59}