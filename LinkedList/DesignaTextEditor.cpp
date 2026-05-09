class TextEditor {
private:
    string left;   // text to the left of cursor
    string right;  // text to the right of cursor

public:
    TextEditor() {
        left = "";
        right = "";
    }
    
    void addText(string text) {
        // Add text at cursor position
        left += text;
    }
    
    int deleteText(int k) {
        // Delete k characters to the left of cursor
        int deleted = min(k, (int)left.size());
        left.erase(left.size() - deleted, deleted);
        return deleted;
    }
    
    string cursorLeft(int k) {
        // Move cursor left k times
        int move = min(k, (int)left.size());
        
        while (move--) {
            right.push_back(left.back());
            left.pop_back();
        }
        
        // Return last 10 characters to the left of cursor
        return left.substr(max(0, (int)left.size() - 10));
    }
    
    string cursorRight(int k) {
        // Move cursor right k times
        int move = min(k, (int)right.size());
        
        while (move--) {
            left.push_back(right.back());
            right.pop_back();
        }
        
        // Return last 10 characters to the left of cursor
        return left.substr(max(0, (int)left.size() - 10));
    }
};
