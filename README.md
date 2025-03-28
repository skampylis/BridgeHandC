# **BridgeHandC**

## **Περιγραφή**
Πρόγραμμα σε **C** για διαχείριση και ανάλυση χεριών στο παιχνίδι Bridge. Υπολογίζει κατανομές φύλλων, πόντους (HCP, declarer), ελέγχει ομαλές κατανομές και προτείνει βέλτιστες δηλώσεις ανοίγματος. Υλοποιεί εισαγωγή/εξαγωγή δεδομένων από αρχεία και διαχείριση πολλαπλών χεριών.

---

### 🔍 **Κύρια Χαρακτηριστικά**
- **Δομή `hand`**: Αποθήκευση 13 καρτών ανά χέρι με αναπαράσταση φύλλων (A, K, Q, J, T) και χρωμάτων (S, H, D, C).
- **Ανάλυση Κατανομής**: Ομαδοποίηση καρτών ανά χρώμα και έλεγχος για ομαλή κατανομή (2+ φύλλα/χρώμα, ≤1 δίφυλλο).
- **Στατιστικές**:
  - **HCP**: Πόντοι ονέρ (4 για Α, 3 για K, 2 για Q, 1 για J).
  - **Declarer Points**: Πόντοι για χρώματα με ≥5 φύλλα.
- **Αυτόματη Δήλωση**: Προτάσεις ανοίγματος (1NT, 2NT, 2 CLUBS, PASS) βάσει πόντων και κατανομής.
- **Διαχείριση Αρχείων**: Εισαγωγή/εξαγωγή χεριών σε αρχεία κειμένου με μορφοποίηση.

---

### ⚙️ **Τεχνολογίες**
- **C** (δομές, δυναμική μνήμη, αρχεία).
- **Αλγόριθμοι**: Ταξινόμηση φύλλων, υπολογισμός στατιστικών, λογική δηλώσεων.
- **Βιβλιοθήκες**: `stdio.h`, `stdlib.h`, `string.h`.

---

### 📝 **Σημειώσεις**
- **Ακαδημαϊκό Πλαίσιο**: Ανάπτυξη σε 2 μέρη (βασική λειτουργικότητα → διαχείριση αρχείων).
- **Επεκτασιμότητα**: Προσθήκη GUI ή υποστήριξη για δικτυακές δηλώσεις.
- **Οδηγίες Χρήσης**: Απαιτείται συγκεκριμένη μορφή εισόδου (βλ. εκφώνηση).

---

**🏷️ Tags**: `C`, `Bridge`, `Data Analysis`, `File I/O`, `Card Games`, `Academic Project`
**🔧 Open for Contributions**: Ανοικτό σε βελτιώσεις μέσω *Pull Requests* ή αναφοράς θεμάτων σε *Issues*.

*"Ιδανικό για εκμάθηση δομών δεδομένων, αλγορίθμων και διαχείρισης αρχείων σε C, με πρακτική εφαρμογή στη στρατηγική του Bridge."* ♠️♥️♦️♣️
