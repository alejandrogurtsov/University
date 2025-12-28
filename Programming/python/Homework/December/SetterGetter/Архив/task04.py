class Word:
    def __init__(self, word: str):
        if not word.isalpha() or not word.isascii():
            raise ValueError("Слово должно состоять только из латинских букв")
        self.word = word

    def __repr__(self):
        return f"Word('{self.word}')"

    def __str__(self):
        return self.word.capitalize()

    def __eq__(self, other):
        if isinstance(other, Word):
            return len(self.word) == len(other.word)
        return NotImplemented

    def __ne__(self, other):
        if isinstance(other, Word):
            return len(self.word) != len(other.word)
        return NotImplemented

    def __lt__(self, other):
        if isinstance(other, Word):
            return len(self.word) < len(other.word)
        return NotImplemented

    def __le__(self, other):
        if isinstance(other, Word):
            return len(self.word) <= len(other.word)
        return NotImplemented

    def __gt__(self, other):
        if isinstance(other, Word):
            return len(self.word) > len(other.word)
        return NotImplemented

    def __ge__(self, other):
        if isinstance(other, Word):
            return len(self.word) >= len(other.word)
        return NotImplemented

w1 = Word("hello")
w2 = Word("world")
w3 = Word("programming")

print(repr(w1))
print(str(w3))

print(w1 == w2)
print(w1 > w3)
print(w3 < w2)
