const addresses = [];
document.querySelectorAll('.f-contacts span').forEach(span => {
    if (span.querySelector('.fa-map-marker') || span.textContent.includes('г. Санкт-Петербург')) {
        addresses.push(span.textContent.trim());
    }
});

const phones = [];
document.querySelectorAll('a[href^="tel:"]').forEach(link => {
    phones.push(link.textContent.trim());
});

const emails = [];
document.querySelectorAll('a[href^="mailto:"]').forEach(link => {
    emails.push(link.textContent.trim());
});

const contactData = {
    university_address: addresses[0] || 'Не найден',
    emails: [...new Set(emails)],
    phones: [...new Set(phones)],
    social_links: Array.from(document.querySelectorAll('.f-socials a')).map(a => a.href)
};

console.log('--- Результаты Варианта №9 ---');
console.table(contactData);