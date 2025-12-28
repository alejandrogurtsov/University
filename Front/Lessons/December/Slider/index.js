const track = document.querySelector('.slider-track');
const slides = document.querySelectorAll('.slide');
const prevBtn = document.querySelector('.arrow.left');
const nextBtn = document.querySelector('.arrow.right');
const windowEl = document.querySelector('.slider-window');

let current = 1;

function updateSlider() {
    slides.forEach(slide => {
        slide.classList.remove('prev', 'active', 'next');
    });

    slides[current].classList.add('active');

    if (slides[current - 1]) {
        slides[current - 1].classList.add('prev');
    }

    if (slides[current + 1]) {
        slides[current + 1].classList.add('next');
    }

    const slideWidth = 220;
    const gap = 40;

    const offset =
        (slideWidth + gap) * current -
        windowEl.offsetWidth / 2 +
        slideWidth / 2;

    track.style.transform = `translateX(${-offset}px)`;
}

nextBtn.onclick = () => {
    if (current < slides.length - 1) {
        current++;
        updateSlider();
    }
};

prevBtn.onclick = () => {
    if (current > 0) {
        current--;
        updateSlider();
    }
};

updateSlider();
