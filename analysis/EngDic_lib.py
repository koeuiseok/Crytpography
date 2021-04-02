def loadDictionary():
    dictionary_file = open('dictionary.txt')
    EnglishWords = {}
    for word in dictionary_file.read().split('\n'): # 사전 파일에서 읽어들이는데 엔터를 기준으로 찾음
        EnglishWords[word] = None   # (key, value) --> # (word, None)
                                    # ex) {'this' : None, 'is' : None}
    dictionary_file.close()
    return EnglishWords

# 전역변수
EnglishWords = loadDictionary()

# 주어진 텍스트가 영어인지 판정하는 함수 만들기
# isEnglish('This is a sample') --> True

# 문자열에서 영문자, 공백만 남기기(특수문자와 숫자 지우기)
UpAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
letters_and_space = UpAlphabet + UpAlphabet.lower() + ' \t\n'   # 공백 추가! ㅇㅇ 공백 없으면 문자가 안되자너~

def removeNoneLetters(message):
    letters_only = []
    for ch in message:
        if ch in letters_and_space: # 공백도 letters_and_space에 포함
            letters_only.append(ch) # 아무것도 없는 letters_only에다가 영어단어와 공백만 쳐넣기
    return ''.join(letters_only)    # 리스트인 letters_only를 문자열로 합쳐버리기! 고것이 리턴값

# 영어자너에 있는 단어의 비율
def percentEnglishWords(message):
    # message = message.upper()   # 혹시 모르니 다 대문자로 변환? 내 파일은 다 소문잔데? 그래서 0퍼뜬거?
    message = message.lower()     # 그럼 난 다 소문자로 해줘야할듯? ㅋㅋ
    message = removeNoneLetters(message)    # 문자 아닌거 다 빼주구요
    possible_words = message.split()        # 공백을 기준으로 단어들을 리스트로 나눈다

    if possible_words == []:    # 0으로 나누는 오류발생을 방지????
        return 0.0
    count_words = 0
    for word in possible_words: # 남은 영단어 리스트들
        if word in EnglishWords:    # 만약 영단어가 English word 라는 전역변수, 영어사전에 있다면
            count_words += 1
    return float(count_words)/len(possible_words)   # 세어진 숫자를 전체 단어수(리스트 수)로 나눈다.

# 영어 판정 함수
# 주어진 문자열이 영어로 된 것인지 판정하는 함수. 복호화한 문장이 바르게 되었는지를 판정할 때 사용
def isEnglish(message, wordPercentage = 20, letterPercentage = 80):
    wordsMatch = percentEnglishWords(message) * 100 >= wordPercentage

    numLetters = len(removeNoneLetters(message))    # 리스트인 letters_only를 문자열로 합친거다.
                                                    # 그것이 리턴인데 그것의 길이를 요구
    messageLettersPercentage = float(numLetters) / len(message) * 100
    lettersMatch = messageLettersPercentage >= letterPercentage

    return wordsMatch and lettersMatch  # 영어 단어의 비율이 충분함 / 영문자의 비율이 충분함







