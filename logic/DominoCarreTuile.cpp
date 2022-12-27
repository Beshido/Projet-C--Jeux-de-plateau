#include "DominoCarreTuile.hpp"
#include <algorithm>

const std::string DominoCarreTuile::getValeurNordString() const {
    return toThreeDigitsString(valeurNord);
}

const std::string DominoCarreTuile::getValeurOuestString() const {
    return toVerticalString(toThreeDigitsString(valeurOuest));
}

const std::string DominoCarreTuile::getValeurEstString() const {
    return toVerticalString(toThreeDigitsString(valeurEst));
}

const std::string DominoCarreTuile::getValeurSudString() const {
    return toThreeDigitsString(valeurSud);
}

void DominoCarreTuile::tournerGauche() {
    const unsigned int temp = valeurNord;
    valeurNord = reverseDigits(valeurEst);
    valeurEst = valeurSud;
    valeurSud = reverseDigits(valeurOuest);
    valeurOuest = temp;
}

void DominoCarreTuile::tournerDroite() {
    unsigned int temp = valeurNord;
    valeurNord = reverseDigits(valeurOuest);
    valeurOuest = valeurSud;
    valeurSud = reverseDigits(valeurEst);
    valeurEst = temp;
}

const unsigned int DominoCarreTuile::reverseDigits(const unsigned int value) const {
    std::string valueString = toThreeDigitsString(value);
    std::reverse(valueString.begin(), valueString.end());
    return std::stoi(valueString);
}

const std::string DominoCarreTuile::toThreeDigitsString(const unsigned int value) const {
    std::string valueString = "000";
    const size_t length = value >= 100 ? 3 : value >= 10 ? 2 : 1;
    const size_t position = 3 - length;
    valueString.replace(position, length, std::to_string(value));
    return valueString;
}

const std::string DominoCarreTuile::toVerticalString(const std::string value) const {
    std::string valueString = value;
    for (size_t i = 1; i < valueString.length(); i += 2)
        valueString.insert(i, "\n");
    return valueString;
}