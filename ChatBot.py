from nltk.chat.util import Chat, reflections

# Define pairs of patterns and responses
pairs = [
    ['hi|hello', ['Hello!', 'Hi there!', 'Hey!']],
    ['how are you?', ['I am good, thank you!', 'Feeling great!', 'I am doing well, thanks for asking.']],
    ['what is your name?', ['I am a chatbot.', 'You can call me a chatbot.']],
    ['bye', ['Goodbye!', 'See you later!', 'Bye!']],
]

# Create a Chat object
chatbot = Chat(pairs, reflections)

# Start chatting
print("Welcome to the chatbot!")
while True:
    user_input = input("You: ")
    if user_input.lower() == 'exit':
        break
    response = chatbot.respond(user_input)
    print("Bot:", response)
