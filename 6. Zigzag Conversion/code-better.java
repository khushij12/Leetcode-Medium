class Solution {
    
    public String convert(String s, int numRows) {
        int length = s.length();
        if (numRows == 1 || numRows >= length) {
            return s;
        }
        char[] chars = new char[length];
        int gap = (numRows - 1) * 2, leftGap = (numRows - 2) * 2, rightGap = 2;
        boolean gapFlag = true;
        int pos = 0;
        int currentRow = 0;
        for (int i = 0; i < length; i++) {
            chars[i] = s.charAt(pos);
            if (currentRow == 0 || currentRow == numRows - 1) {
                pos = pos + gap;
                if (pos >= length) { // overflow
                    currentRow++;
                    pos = currentRow;
                }
            } else {
                if (gapFlag) {
                    pos = pos + leftGap;
                } else {
                    pos = pos + rightGap;
                }
                gapFlag = !gapFlag;
                if (pos >= length) { // overflow
                    currentRow++;
                    leftGap -= 2;
                    rightGap += 2;
                    pos = currentRow;
                    gapFlag = true;
                }
            }
        }
        return new String(chars);
    }
}